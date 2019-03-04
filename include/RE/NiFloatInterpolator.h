#pragma once

#include "RE/NiKeyBasedInterpolator.h"  // NiKeyBasedInterpolator
#include "RE/NiSmartPointer.h"  // NiPointer


namespace RE
{
	class NiFloatData;


	class NiFloatInterpolator : public NiKeyBasedInterpolator
	{
	public:
		virtual ~NiFloatInterpolator();																	// 00

		// override (NiKeyBasedInterpolator)
		virtual NiRTTI*			GetRTTI() override;														// 02
		virtual NiObject*		CreateClone(NiCloningProcess a_cloner) override;						// 17
		virtual void			LoadBinary(NiStream* a_stream) override;								// 18
		virtual bool			RegisterStreamables(NiStream* a_stream) override;						// 1A
		virtual void			SaveBinary(NiStream* a_stream) override;								// 1B
		virtual bool			IsEqual(NiObject* a_object) override;									// 1C
		virtual bool			Update(float a_delta, NiObjectNET* a_target, float* a_data) override;	// 29
		virtual bool			IsFloatValueSupported() const override;									// 2C - { return true; }
		virtual void			Collapse() override;													// 31
		virtual void			GuaranteeTimeRange(float a_start, float a_end) override;				// 33
		virtual NiInterpolator*	GetSequenceInterpolator(float a_start, float a_end) override;			// 34
		virtual UInt16			GetKeyChannelCount() const override;									// 39 - { return 1; }
		virtual UInt32			GetKeyCount(UInt16 a_channel) const override;							// 3A - { return data ? data->count : 0; }
		virtual UInt32			GetKeyContent(UInt16 a_channel) const override;							// 3B - { return data ? data->content : 0; }
		virtual KeyType			GetKeyType(UInt16 a_channel) const override;							// 3C - { return 0; }
		virtual void*			GetKeyArray(UInt16 a_channel) const override;							// 3D - { return data ? data->arr : 0; }
		virtual UInt8			GetKeyStride(UInt16 a_channel) const override;							// 3E - { return data ? data->stride : 0; }
		virtual bool			GetChannelPosed(UInt16 a_channel) const override;						// 3F - { return !data && value != -3.4028235e38; }


		// members
		float					value;		// 18
		UInt32					pad1C;		// 1C
		NiPointer<NiFloatData>	data;		// 20
		UInt32					lastIndex;	// 28
		UInt32					pad2C;		// 2C
	};
	STATIC_ASSERT(sizeof(NiFloatInterpolator) == 0x30);
}