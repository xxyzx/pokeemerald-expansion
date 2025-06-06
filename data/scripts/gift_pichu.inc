MysteryGiftScript_SurfPichu::
	setvaddress MysteryGiftScript_SurfPichu
	vgoto_if_unset FLAG_MYSTERY_GIFT_DONE, SurfPichu_GiveIfPossible
	returnram

SurfPichu_GiveIfPossible:
	specialvar VAR_GIFT_PICHU_SLOT, CalculatePlayerPartyCount
	vgoto_if_eq VAR_GIFT_PICHU_SLOT, PARTY_SIZE, SurfPichu_FullParty
	setflag FLAG_MYSTERY_GIFT_DONE
	vcall SurfPichu_GiveEgg
	lock
	faceplayer
	vmessage sText_MysteryGiftEgg
	waitmessage
	waitbuttonpress
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	release
	end

SurfPichu_FullParty:
	lock
	faceplayer
	vmessage sText_FullParty
	waitmessage
	waitbuttonpress
	release
	end

SurfPichu_GiveEgg:
	giveegg SPECIES_PICHU
	setmodernfatefulencounter VAR_GIFT_PICHU_SLOT
	setmonmetlocation VAR_GIFT_PICHU_SLOT, METLOC_FATEFUL_ENCOUNTER
	vgoto_if_eq VAR_GIFT_PICHU_SLOT, 1, SurfPichu_Slot1
	vgoto_if_eq VAR_GIFT_PICHU_SLOT, 2, SurfPichu_Slot2
	vgoto_if_eq VAR_GIFT_PICHU_SLOT, 3, SurfPichu_Slot3
	vgoto_if_eq VAR_GIFT_PICHU_SLOT, 4, SurfPichu_Slot4
	vgoto_if_eq VAR_GIFT_PICHU_SLOT, 5, SurfPichu_Slot5
	return

SurfPichu_Slot1:
	setmonmove 1, 2, MOVE_SURF
	return

SurfPichu_Slot2::
	setmonmove 2, 2, MOVE_SURF
	return

SurfPichu_Slot3:
	setmonmove 3, 2, MOVE_SURF
	return

SurfPichu_Slot4:
	setmonmove 4, 2, MOVE_SURF
	return

SurfPichu_Slot5:
	setmonmove 5, 2, MOVE_SURF
	return

sText_MysteryGiftEgg:
	.string "感谢使用\n"
	.string "神秘礼物系统。\p"
	.string "从宝可梦中心我们\n"
	.string "得到一个礼物——宝可梦蛋！\p"
	.string "请用爱心和关怀\n"
	.string "来培育它。$"

sText_FullParty:
	.string "你的队伍看起来满了。\p"
	.string "请保存一只宝可梦\n"
	.string "到电脑中再来吧。$"
