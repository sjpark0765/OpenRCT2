#pragma region Copyright (c) 2014-2017 OpenRCT2 Developers
/*****************************************************************************
 * OpenRCT2, an open source clone of Roller Coaster Tycoon 2.
 *
 * OpenRCT2 is the work of many authors, a full list can be found in contributors.md
 * For more information, visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * A full copy of the GNU General Public License can be found in licence.txt
 *****************************************************************************/
#pragma endregion

#pragma once

#include "../common.h"
#include "../object/Object.h"
#include "Ride.h"

#pragma pack(push, 1)
struct rct_trackdefinition
{
    uint8 type;
    uint8 vangle_end;
    uint8 vangle_start;
    uint8 bank_end;
    uint8 bank_start;
    sint8 preview_z_offset;
    uint8 pad[2];
};
assert_struct_size(rct_trackdefinition, 8);
#pragma pack(pop)

/**
* Size: 0x0A
*/
struct rct_preview_track
{
    uint8  index;    // 0x00
    sint16 x;       // 0x01
    sint16 y;       // 0x03
    sint16 z;       // 0x05
    uint8  var_07;
    uint8  var_08;
    uint8  var_09;
};

/* size 0x0A */
struct rct_track_coordinates
{
    sint8  rotation_begin;   // 0x00
    sint8  rotation_end;     // 0x01
    sint16 z_begin;         // 0x02
    sint16 z_end;           // 0x04
    sint16 x;               // 0x06
    sint16 y;               // 0x08
};

enum
{
    TRACK_ELEMENT_FLAG_TERMINAL_STATION = 1 << 3,
    TRACK_ELEMENT_FLAG_INVERTED         = 1 << 6,
    TRACK_ELEMENT_FLAG_CHAIN_LIFT       = 1 << 7,
};

enum
{
    // Not anything to do with colour but uses
    // that field in the map element

    // Used for multi-dimension coaster
        TRACK_ELEMENT_COLOUR_FLAG_INVERTED = (1 << 2),

    // Used for giga coaster
        TRACK_ELEMENT_COLOUR_FLAG_CABLE_LIFT = (1 << 3),
};

#define TRACK_ELEMENT_FLAG_MAGNITUDE_MASK 0x0F
#define TRACK_ELEMENT_FLAG_COLOUR_MASK 0x30
#define TRACK_ELEMENT_FLAG_STATION_NO_MASK 0x02

#define MAX_STATION_PLATFORM_LENGTH 32

enum
{
    TRACK_NONE = 0,

    TRACK_FLAT    = 0,
    TRACK_STRAIGHT,
    TRACK_STATION_END,
    TRACK_LIFT_HILL,
    TRACK_LIFT_HILL_STEEP,
    TRACK_LIFT_HILL_CURVE,
    TRACK_FLAT_ROLL_BANKING,
    TRACK_VERTICAL_LOOP,
    TRACK_SLOPE,
    TRACK_SLOPE_STEEP,
    TRACK_SLOPE_LONG,
    TRACK_SLOPE_CURVE,
    TRACK_SLOPE_CURVE_STEEP,
    TRACK_S_BEND,
    TRACK_CURVE_VERY_SMALL,
    TRACK_CURVE_SMALL,
    TRACK_CURVE,
    TRACK_TWIST,
    TRACK_HALF_LOOP,
    TRACK_CORKSCREW,
    TRACK_TOWER_BASE,
    TRACK_HELIX_SMALL,
    TRACK_HELIX_LARGE,
    TRACK_HELIX_LARGE_UNBANKED,
    TRACK_BRAKES,
    TRACK_25,
    TRACK_ON_RIDE_PHOTO,
    TRACK_WATER_SPLASH,
    TRACK_SLOPE_VERTICAL,
    TRACK_BARREL_ROLL,
    TRACK_POWERED_LIFT,
    TRACK_HALF_LOOP_LARGE,
    TRACK_SLOPE_CURVE_BANKED,
    TRACK_LOG_FLUME_REVERSER,
    TRACK_HEARTLINE_ROLL,
    TRACK_REVERSER,
    TRACK_REVERSE_FREEFALL,
    TRACK_SLOPE_TO_FLAT,
    TRACK_BLOCK_BRAKES,
    TRACK_SLOPE_ROLL_BANKING,
    TRACK_SLOPE_STEEP_LONG,
    TRACK_CURVE_VERTICAL,
    TRACK_42,
    TRACK_LIFT_HILL_CABLE,
    TRACK_LIFT_HILL_CURVED,
    TRACK_QUARTER_LOOP,
    TRACK_SPINNING_TUNNEL,
    TRACK_ROTATION_CONTROL_TOGGLE,
    TRACK_INLINE_TWIST_UNINVERTED,
    TRACK_INLINE_TWIST_INVERTED,
    TRACK_QUARTER_LOOP_UNINVERTED,
    TRACK_QUARTER_LOOP_INVERTED,
    TRACK_RAPIDS,
    TRACK_HALF_LOOP_UNINVERTED,
    TRACK_HALF_LOOP_INVERTED,
    TRACK_BOOSTER = TRACK_ROTATION_CONTROL_TOGGLE,

    TRACK_WATERFALL      = 152,
    TRACK_WHIRLPOOL      = 152,
    TRACK_BRAKE_FOR_DROP = 172,
    TRACK_190            = 190,
    TRACK_192            = 192,
    TRACK_194            = 194,
    TRACK_MINI_GOLF_HOLE = 195,
};

enum
{
    TRACK_CURVE_LEFT_VERY_SMALL  = 5,
    TRACK_CURVE_LEFT_SMALL       = 3,
    TRACK_CURVE_LEFT             = 1,
    TRACK_CURVE_LEFT_LARGE       = 7,
    TRACK_CURVE_NONE             = 0,
    TRACK_CURVE_RIGHT_LARGE      = 8,
    TRACK_CURVE_RIGHT            = 2,
    TRACK_CURVE_RIGHT_SMALL      = 4,
    TRACK_CURVE_RIGHT_VERY_SMALL = 6
};

enum
{
    TRACK_SLOPE_NONE    = 0,
    TRACK_SLOPE_UP_25   = 2,
    TRACK_SLOPE_UP_60   = 4,
    TRACK_SLOPE_DOWN_25 = 6,
    TRACK_SLOPE_DOWN_60 = 8,
    TRACK_SLOPE_UP_90   = 10,
    TRACK_SLOPE_DOWN_90 = 18,

    TRACK_VANGLE_TOWER            = 10,
    TRACK_VANGLE_REVERSE_FREEFALL = 10
};

enum
{
    TRACK_BANK_NONE        = 0,
    TRACK_BANK_LEFT        = 2,
    TRACK_BANK_RIGHT       = 4,
    TRACK_BANK_UPSIDE_DOWN = 15,
};

enum
{
    TRACK_ELEM_FLAG_ONLY_UNDERWATER       = (1 << 0),
    TRACK_ELEM_FLAG_TURN_LEFT             = (1 << 1),
    TRACK_ELEM_FLAG_TURN_RIGHT            = (1 << 2),
    TRACK_ELEM_FLAG_TURN_BANKED           = (1 << 3),
    TRACK_ELEM_FLAG_TURN_SLOPED           = (1 << 4),
    TRACK_ELEM_FLAG_DOWN                  = (1 << 5),
    TRACK_ELEM_FLAG_UP                    = (1 << 6),
    TRACK_ELEM_FLAG_NORMAL_TO_INVERSION   = (1 << 7),
    TRACK_ELEM_FLAG_STARTS_AT_HALF_HEIGHT = (1 << 8),
    TRACK_ELEM_FLAG_ONLY_ABOVE_GROUND     = (1 << 9),
    TRACK_ELEM_FLAG_IS_STEEP_UP           = (1 << 10), // Used to allow steep backwards lifts on roller coasters that do not allow steep forward lift hills
    TRACK_ELEM_FLAG_HELIX                 = (1 << 11),
    TRACK_ELEM_FLAG_ALLOW_LIFT_HILL       = (1 << 12),
    TRACK_ELEM_FLAG_CURVE_ALLOWS_LIFT     = (1 << 13),
    TRACK_ELEM_FLAG_INVERSION_TO_NORMAL   = (1 << 14),
    TRACK_ELEM_FLAG_BANKED                = (1 << 15), // Also set on Spinning Tunnel and Log Flume reverser, probably to save a flag.
};

enum
{
    TRACK_ELEM_FLAT,
    TRACK_ELEM_END_STATION,
    TRACK_ELEM_BEGIN_STATION,
    TRACK_ELEM_MIDDLE_STATION,
    TRACK_ELEM_25_DEG_UP,
    TRACK_ELEM_60_DEG_UP,
    TRACK_ELEM_FLAT_TO_25_DEG_UP,
    TRACK_ELEM_25_DEG_UP_TO_60_DEG_UP,
    TRACK_ELEM_60_DEG_UP_TO_25_DEG_UP,
    TRACK_ELEM_25_DEG_UP_TO_FLAT,
    TRACK_ELEM_25_DEG_DOWN                                        = 10,
    TRACK_ELEM_60_DEG_DOWN,
    TRACK_ELEM_FLAT_TO_25_DEG_DOWN,
    TRACK_ELEM_25_DEG_DOWN_TO_60_DEG_DOWN,
    TRACK_ELEM_60_DEG_DOWN_TO_25_DEG_DOWN,
    TRACK_ELEM_25_DEG_DOWN_TO_FLAT,
    TRACK_ELEM_LEFT_QUARTER_TURN_5_TILES,
    TRACK_ELEM_RIGHT_QUARTER_TURN_5_TILES,
    TRACK_ELEM_FLAT_TO_LEFT_BANK,
    TRACK_ELEM_FLAT_TO_RIGHT_BANK,
    TRACK_ELEM_LEFT_BANK_TO_FLAT                                  = 20,
    TRACK_ELEM_RIGHT_BANK_TO_FLAT,
    TRACK_ELEM_BANKED_LEFT_QUARTER_TURN_5_TILES,
    TRACK_ELEM_BANKED_RIGHT_QUARTER_TURN_5_TILES,
    TRACK_ELEM_LEFT_BANK_TO_25_DEG_UP,
    TRACK_ELEM_RIGHT_BANK_TO_25_DEG_UP,
    TRACK_ELEM_25_DEG_UP_TO_LEFT_BANK,
    TRACK_ELEM_25_DEG_UP_TO_RIGHT_BANK,
    TRACK_ELEM_LEFT_BANK_TO_25_DEG_DOWN,
    TRACK_ELEM_RIGHT_BANK_TO_25_DEG_DOWN,
    TRACK_ELEM_25_DEG_DOWN_TO_LEFT_BANK                           = 30,
    TRACK_ELEM_25_DEG_DOWN_TO_RIGHT_BANK,
    TRACK_ELEM_LEFT_BANK,
    TRACK_ELEM_RIGHT_BANK,
    TRACK_ELEM_LEFT_QUARTER_TURN_5_TILES_25_DEG_UP,
    TRACK_ELEM_RIGHT_QUARTER_TURN_5_TILES_25_DEG_UP,
    TRACK_ELEM_LEFT_QUARTER_TURN_5_TILES_25_DEG_DOWN,
    TRACK_ELEM_RIGHT_QUARTER_TURN_5_TILES_25_DEG_DOWN,
    TRACK_ELEM_S_BEND_LEFT,
    TRACK_ELEM_S_BEND_RIGHT,
    TRACK_ELEM_LEFT_VERTICAL_LOOP                                 = 40,
    TRACK_ELEM_RIGHT_VERTICAL_LOOP,
    TRACK_ELEM_LEFT_QUARTER_TURN_3_TILES,
    TRACK_ELEM_RIGHT_QUARTER_TURN_3_TILES,
    TRACK_ELEM_LEFT_QUARTER_TURN_3_TILES_BANK,
    TRACK_ELEM_RIGHT_QUARTER_TURN_3_TILES_BANK,
    TRACK_ELEM_LEFT_QUARTER_TURN_3_TILES_25_DEG_UP,
    TRACK_ELEM_RIGHT_QUARTER_TURN_3_TILES_25_DEG_UP,
    TRACK_ELEM_LEFT_QUARTER_TURN_3_TILES_25_DEG_DOWN,
    TRACK_ELEM_RIGHT_QUARTER_TURN_3_TILES_25_DEG_DOWN,
    TRACK_ELEM_LEFT_QUARTER_TURN_1_TILE                           = 50,
    TRACK_ELEM_RIGHT_QUARTER_TURN_1_TILE,
    TRACK_ELEM_LEFT_TWIST_DOWN_TO_UP,
    TRACK_ELEM_RIGHT_TWIST_DOWN_TO_UP,
    TRACK_ELEM_LEFT_TWIST_UP_TO_DOWN,
    TRACK_ELEM_RIGHT_TWIST_UP_TO_DOWN,
    TRACK_ELEM_HALF_LOOP_UP,
    TRACK_ELEM_HALF_LOOP_DOWN,
    TRACK_ELEM_LEFT_CORKSCREW_UP,
    TRACK_ELEM_RIGHT_CORKSCREW_UP,
    TRACK_ELEM_LEFT_CORKSCREW_DOWN                                = 60,
    TRACK_ELEM_RIGHT_CORKSCREW_DOWN,
    TRACK_ELEM_FLAT_TO_60_DEG_UP,
    TRACK_ELEM_60_DEG_UP_TO_FLAT,
    TRACK_ELEM_FLAT_TO_60_DEG_DOWN,
    TRACK_ELEM_60_DEG_DOWN_TO_FLAT,
    TRACK_ELEM_TOWER_BASE,
    TRACK_ELEM_TOWER_SECTION,
    TRACK_ELEM_FLAT_COVERED,
    TRACK_ELEM_25_DEG_UP_COVERED,
    TRACK_ELEM_60_DEG_UP_COVERED                                  = 70,
    TRACK_ELEM_FLAT_TO_25_DEG_UP_COVERED,
    TRACK_ELEM_25_DEG_UP_TO_60_DEG_UP_COVERED,
    TRACK_ELEM_60_DEG_UP_TO_25_DEG_UP_COVERED,
    TRACK_ELEM_25_DEG_UP_TO_FLAT_COVERED,
    TRACK_ELEM_25_DEG_DOWN_COVERED,
    TRACK_ELEM_60_DEG_DOWN_COVERED,
    TRACK_ELEM_FLAT_TO_25_DEG_DOWN_COVERED,
    TRACK_ELEM_25_DEG_DOWN_TO_60_DEG_DOWN_COVERED,
    TRACK_ELEM_60_DEG_DOWN_TO_25_DEG_DOWN_COVERED,
    TRACK_ELEM_25_DEG_DOWN_TO_FLAT_COVERED                        = 80,
    TRACK_ELEM_LEFT_QUARTER_TURN_5_TILES_COVERED,
    TRACK_ELEM_RIGHT_QUARTER_TURN_5_TILES_COVERED,
    TRACK_ELEM_S_BEND_LEFT_COVERED,
    TRACK_ELEM_S_BEND_RIGHT_COVERED,
    TRACK_ELEM_LEFT_QUARTER_TURN_3_TILES_COVERED,
    TRACK_ELEM_RIGHT_QUARTER_TURN_3_TILES_COVERED,
    TRACK_ELEM_LEFT_HALF_BANKED_HELIX_UP_SMALL,
    TRACK_ELEM_RIGHT_HALF_BANKED_HELIX_UP_SMALL,
    TRACK_ELEM_LEFT_HALF_BANKED_HELIX_DOWN_SMALL,
    TRACK_ELEM_RIGHT_HALF_BANKED_HELIX_DOWN_SMALL                 = 90,
    TRACK_ELEM_LEFT_HALF_BANKED_HELIX_UP_LARGE,
    TRACK_ELEM_RIGHT_HALF_BANKED_HELIX_UP_LARGE,
    TRACK_ELEM_LEFT_HALF_BANKED_HELIX_DOWN_LARGE,
    TRACK_ELEM_RIGHT_HALF_BANKED_HELIX_DOWN_LARGE,
    TRACK_ELEM_LEFT_QUARTER_TURN_1_TILE_60_DEG_UP,
    TRACK_ELEM_RIGHT_QUARTER_TURN_1_TILE_60_DEG_UP,
    TRACK_ELEM_LEFT_QUARTER_TURN_1_TILE_60_DEG_DOWN,
    TRACK_ELEM_RIGHT_QUARTER_TURN_1_TILE_60_DEG_DOWN,
    TRACK_ELEM_BRAKES,
    TRACK_ELEM_ROTATION_CONTROL_TOGGLE                            = 100,
    TRACK_ELEM_BOOSTER                                            = 100,
    TRACK_ELEM_INVERTED_90_DEG_UP_TO_FLAT_QUARTER_LOOP            = 101,
    TRACK_ELEM_MAZE                                               = 101,
    TRACK_ELEM_255_ALIAS                                          = 101, // Used by the multi-dimension coaster, as TD6 cannot handle index 255.
    TRACK_ELEM_LEFT_QUARTER_BANKED_HELIX_LARGE_UP,
    TRACK_ELEM_RIGHT_QUARTER_BANKED_HELIX_LARGE_UP,
    TRACK_ELEM_LEFT_QUARTER_BANKED_HELIX_LARGE_DOWN,
    TRACK_ELEM_RIGHT_QUARTER_BANKED_HELIX_LARGE_DOWN,
    TRACK_ELEM_LEFT_QUARTER_HELIX_LARGE_UP,
    TRACK_ELEM_RIGHT_QUARTER_HELIX_LARGE_UP,
    TRACK_ELEM_LEFT_QUARTER_HELIX_LARGE_DOWN,
    TRACK_ELEM_RIGHT_QUARTER_HELIX_LARGE_DOWN,
    TRACK_ELEM_25_DEG_UP_LEFT_BANKED                              = 110,
    TRACK_ELEM_25_DEG_UP_RIGHT_BANKED,
    TRACK_ELEM_WATERFALL,
    TRACK_ELEM_RAPIDS,
    TRACK_ELEM_ON_RIDE_PHOTO,
    TRACK_ELEM_25_DEG_DOWN_LEFT_BANKED,
    TRACK_ELEM_25_DEG_DOWN_RIGHT_BANKED,
    TRACK_ELEM_WATER_SPLASH,
    TRACK_ELEM_FLAT_TO_60_DEG_UP_LONG_BASE,
    TRACK_ELEM_60_DEG_UP_TO_FLAT_LONG_BASE,
    TRACK_ELEM_WHIRLPOOL                                          = 120,
    TRACK_ELEM_FLAT_TO_60_DEG_DOWN_LONG_BASE,
    TRACK_ELEM_60_DEG_UP_TO_FLAT_LONG_BASE_122,
    TRACK_ELEM_CABLE_LIFT_HILL,
    TRACK_ELEM_REVERSE_FREEFALL_SLOPE,
    TRACK_ELEM_REVERSE_FREEFALL_VERTICAL,
    TRACK_ELEM_90_DEG_UP,
    TRACK_ELEM_90_DEG_DOWN,
    TRACK_ELEM_60_DEG_UP_TO_90_DEG_UP,
    TRACK_ELEM_90_DEG_DOWN_TO_60_DEG_DOWN,
    TRACK_ELEM_90_DEG_UP_TO_60_DEG_UP                             = 130,
    TRACK_ELEM_60_DEG_DOWN_TO_90_DEG_DOWN,
    TRACK_ELEM_BRAKE_FOR_DROP,
    TRACK_ELEM_LEFT_EIGHTH_TO_DIAG,
    TRACK_ELEM_RIGHT_EIGHTH_TO_DIAG,
    TRACK_ELEM_LEFT_EIGHTH_TO_ORTHOGONAL,
    TRACK_ELEM_RIGHT_EIGHTH_TO_ORTHOGONAL,
    TRACK_ELEM_LEFT_EIGHTH_BANK_TO_DIAG,
    TRACK_ELEM_RIGHT_EIGHTH_BANK_TO_DIAG,
    TRACK_ELEM_LEFT_EIGHTH_BANK_TO_ORTHOGONAL,
    TRACK_ELEM_RIGHT_EIGHTH_BANK_TO_ORTHOGONAL                    = 140,
    TRACK_ELEM_DIAG_FLAT,
    TRACK_ELEM_DIAG_25_DEG_UP,
    TRACK_ELEM_DIAG_60_DEG_UP,
    TRACK_ELEM_DIAG_FLAT_TO_25_DEG_UP,
    TRACK_ELEM_DIAG_25_DEG_UP_TO_60_DEG_UP,
    TRACK_ELEM_DIAG_60_DEG_UP_TO_25_DEG_UP,
    TRACK_ELEM_DIAG_25_DEG_UP_TO_FLAT,
    TRACK_ELEM_DIAG_25_DEG_DOWN,
    TRACK_ELEM_DIAG_60_DEG_DOWN,
    TRACK_ELEM_DIAG_FLAT_TO_25_DEG_DOWN                           = 150,
    TRACK_ELEM_DIAG_25_DEG_DOWN_TO_60_DEG_DOWN,
    TRACK_ELEM_DIAG_60_DEG_DOWN_TO_25_DEG_DOWN,
    TRACK_ELEM_DIAG_25_DEG_DOWN_TO_FLAT,
    TRACK_ELEM_DIAG_FLAT_TO_60_DEG_UP,
    TRACK_ELEM_DIAG_60_DEG_UP_TO_FLAT,
    TRACK_ELEM_DIAG_FLAT_TO_60_DEG_DOWN,
    TRACK_ELEM_DIAG_60_DEG_DOWN_TO_FLAT,
    TRACK_ELEM_DIAG_FLAT_TO_LEFT_BANK,
    TRACK_ELEM_DIAG_FLAT_TO_RIGHT_BANK,
    TRACK_ELEM_DIAG_LEFT_BANK_TO_FLAT                             = 160,
    TRACK_ELEM_DIAG_RIGHT_BANK_TO_FLAT,
    TRACK_ELEM_DIAG_LEFT_BANK_TO_25_DEG_UP,
    TRACK_ELEM_DIAG_RIGHT_BANK_TO_25_DEG_UP,
    TRACK_ELEM_DIAG_25_DEG_UP_TO_LEFT_BANK,
    TRACK_ELEM_DIAG_25_DEG_UP_TO_RIGHT_BANK,
    TRACK_ELEM_DIAG_LEFT_BANK_TO_25_DEG_DOWN,
    TRACK_ELEM_DIAG_RIGHT_BANK_TO_25_DEG_DOWN,
    TRACK_ELEM_DIAG_25_DEG_DOWN_TO_LEFT_BANK,
    TRACK_ELEM_DIAG_25_DEG_DOWN_TO_RIGHT_BANK,
    TRACK_ELEM_DIAG_LEFT_BANK                                     = 170,
    TRACK_ELEM_DIAG_RIGHT_BANK,
    TRACK_ELEM_LOG_FLUME_REVERSER,
    TRACK_ELEM_SPINNING_TUNNEL,
    TRACK_ELEM_LEFT_BARREL_ROLL_UP_TO_DOWN,
    TRACK_ELEM_RIGHT_BARREL_ROLL_UP_TO_DOWN,
    TRACK_ELEM_LEFT_BARREL_ROLL_DOWN_TO_UP,
    TRACK_ELEM_RIGHT_BARREL_ROLL_DOWN_TO_UP,
    TRACK_ELEM_LEFT_BANK_TO_LEFT_QUARTER_TURN_3_TILES_25_DEG_UP,
    TRACK_ELEM_RIGHT_BANK_TO_RIGHT_QUARTER_TURN_3_TILES_25_DEG_UP,
    TRACK_ELEM_LEFT_QUARTER_TURN_3_TILES_25_DEG_DOWN_TO_LEFT_BANK = 180,
    TRACK_ELEM_RIGHT_QUARTER_TURN_3_TILES_25_DEG_DOWN_TO_RIGHT_BANK,
    TRACK_ELEM_POWERED_LIFT,
    TRACK_ELEM_LEFT_LARGE_HALF_LOOP_UP,
    TRACK_ELEM_RIGHT_LARGE_HALF_LOOP_UP,
    TRACK_ELEM_RIGHT_LARGE_HALF_LOOP_DOWN,
    TRACK_ELEM_LEFT_LARGE_HALF_LOOP_DOWN,
    TRACK_ELEM_LEFT_FLYER_TWIST_UP,
    TRACK_ELEM_RIGHT_FLYER_TWIST_UP,
    TRACK_ELEM_LEFT_FLYER_TWIST_DOWN,
    TRACK_ELEM_RIGHT_FLYER_TWIST_DOWN                             = 190,
    TRACK_ELEM_FLYER_HALF_LOOP_UP,
    TRACK_ELEM_FLYER_HALF_LOOP_DOWN,
    TRACK_ELEM_LEFT_FLYER_CORKSCREW_UP,
    TRACK_ELEM_RIGHT_FLYER_CORKSCREW_UP,
    TRACK_ELEM_LEFT_FLYER_CORKSCREW_DOWN,
    TRACK_ELEM_RIGHT_FLYER_CORKSCREW_DOWN,
    TRACK_ELEM_HEARTLINE_TRANSFER_UP,
    TRACK_ELEM_HEARTLINE_TRANSFER_DOWN,
    TRACK_ELEM_LEFT_HEARTLINE_ROLL,
    TRACK_ELEM_RIGHT_HEARTLINE_ROLL                               = 200,
    TRACK_ELEM_MINI_GOLF_HOLE_A,
    TRACK_ELEM_MINI_GOLF_HOLE_B,
    TRACK_ELEM_MINI_GOLF_HOLE_C,
    TRACK_ELEM_MINI_GOLF_HOLE_D,
    TRACK_ELEM_MINI_GOLF_HOLE_E,
    TRACK_ELEM_MULTIDIM_INVERTED_FLAT_TO_90_DEG_QUARTER_LOOP_DOWN,
    TRACK_ELEM_90_DEG_TO_INVERTED_FLAT_QUARTER_LOOP_UP,
    TRACK_ELEM_INVERTED_FLAT_TO_90_DEG_QUARTER_LOOP_DOWN,
    TRACK_ELEM_LEFT_CURVED_LIFT_HILL,
    TRACK_ELEM_RIGHT_CURVED_LIFT_HILL                             = 210,
    TRACK_ELEM_LEFT_REVERSER,
    TRACK_ELEM_RIGHT_REVERSER,
    TRACK_ELEM_AIR_THRUST_TOP_CAP,
    TRACK_ELEM_AIR_THRUST_VERTICAL_DOWN,
    TRACK_ELEM_AIR_THRUST_VERTICAL_DOWN_TO_LEVEL,
    TRACK_ELEM_BLOCK_BRAKES,
    TRACK_ELEM_LEFT_BANKED_QUARTER_TURN_3_TILE_25_DEG_UP,
    TRACK_ELEM_RIGHT_BANKED_QUARTER_TURN_3_TILE_25_DEG_UP,
    TRACK_ELEM_LEFT_BANKED_QUARTER_TURN_3_TILE_25_DEG_DOWN,
    TRACK_ELEM_RIGHT_BANKED_QUARTER_TURN_3_TILE_25_DEG_DOWN,
    TRACK_ELEM_LEFT_BANKED_QUARTER_TURN_5_TILE_25_DEG_UP,
    TRACK_ELEM_RIGHT_BANKED_QUARTER_TURN_5_TILE_25_DEG_UP,
    TRACK_ELEM_LEFT_BANKED_QUARTER_TURN_5_TILE_25_DEG_DOWN,
    TRACK_ELEM_RIGHT_BANKED_QUARTER_TURN_5_TILE_25_DEG_DOWN,
    TRACK_ELEM_25_DEG_UP_TO_LEFT_BANKED_25_DEG_UP,
    TRACK_ELEM_25_DEG_UP_TO_RIGHT_BANKED_25_DEG_UP,
    TRACK_ELEM_LEFT_BANKED_25_DEG_UP_TO_25_DEG_UP,
    TRACK_ELEM_RIGHT_BANKED_25_DEG_UP_TO_25_DEG_UP,
    TRACK_ELEM_25_DEG_DOWN_TO_LEFT_BANKED_25_DEG_DOWN,
    TRACK_ELEM_25_DEG_DOWN_TO_RIGHT_BANKED_25_DEG_DOWN,
    TRACK_ELEM_LEFT_BANKED_25_DEG_DOWN_TO_25_DEG_DOWN,
    TRACK_ELEM_RIGHT_BANKED_25_DEG_DOWN_TO_25_DEG_DOWN,
    TRACK_ELEM_LEFT_BANKED_FLAT_TO_LEFT_BANKED_25_DEG_UP,
    TRACK_ELEM_RIGHT_BANKED_FLAT_TO_RIGHT_BANKED_25_DEG_UP,
    TRACK_ELEM_LEFT_BANKED_25_DEG_UP_TO_LEFT_BANKED_FLAT,
    TRACK_ELEM_RIGHT_BANKED_25_DEG_UP_TO_RIGHT_BANKED_FLAT,
    TRACK_ELEM_LEFT_BANKED_FLAT_TO_LEFT_BANKED_25_DEG_DOWN,
    TRACK_ELEM_RIGHT_BANKED_FLAT_TO_RIGHT_BANKED_25_DEG_DOWN,
    TRACK_ELEM_LEFT_BANKED_25_DEG_DOWN_TO_LEFT_BANKED_FLAT,
    TRACK_ELEM_RIGHT_BANKED_25_DEG_DOWN_TO_RIGHT_BANKED_FLAT,
    TRACK_ELEM_FLAT_TO_LEFT_BANKED_25_DEG_UP,
    TRACK_ELEM_FLAT_TO_RIGHT_BANKED_25_DEG_UP,
    TRACK_ELEM_LEFT_BANKED_25_DEG_UP_TO_FLAT,
    TRACK_ELEM_RIGHT_BANKED_25_DEG_UP_TO_FLAT,
    TRACK_ELEM_FLAT_TO_LEFT_BANKED_25_DEG_DOWN,
    TRACK_ELEM_FLAT_TO_RIGHT_BANKED_25_DEG_DOWN,
    TRACK_ELEM_LEFT_BANKED_25_DEG_DOWN_TO_FLAT,
    TRACK_ELEM_RIGHT_BANKED_25_DEG_DOWN_TO_FLAT,
    TRACK_ELEM_LEFT_QUARTER_TURN_1_TILE_90_DEG_UP,
    TRACK_ELEM_RIGHT_QUARTER_TURN_1_TILE_90_DEG_UP,
    TRACK_ELEM_LEFT_QUARTER_TURN_1_TILE_90_DEG_DOWN,
    TRACK_ELEM_RIGHT_QUARTER_TURN_1_TILE_90_DEG_DOWN,
    TRACK_ELEM_MULTIDIM_90_DEG_UP_TO_INVERTED_FLAT_QUARTER_LOOP,
    TRACK_ELEM_MULTIDIM_FLAT_TO_90_DEG_DOWN_QUARTER_LOOP,
    TRACK_ELEM_255,
};

enum
{
    FLAT_TRACK_ELEM_1_X_4_A = 95,
    FLAT_TRACK_ELEM_2_X_2   = 110,
    FLAT_TRACK_ELEM_4_X_4   = 111,
    FLAT_TRACK_ELEM_1_X_5   = 116,
    FLAT_TRACK_ELEM_1_X_1_A = 118,
    FLAT_TRACK_ELEM_1_X_4_B = 119,
    FLAT_TRACK_ELEM_1_X_1_B = 121,
    FLAT_TRACK_ELEM_1_X_4_C = 122,
    FLAT_TRACK_ELEM_3_X_3   = 123,
};

enum
{
    TRACK_SEQUENCE_FLAG_DIRECTION_0      = (1 << 0),
    TRACK_SEQUENCE_FLAG_DIRECTION_1      = (1 << 1),
    TRACK_SEQUENCE_FLAG_DIRECTION_2      = (1 << 2),
    TRACK_SEQUENCE_FLAG_DIRECTION_3      = (1 << 3),
    TRACK_SEQUENCE_FLAG_ORIGIN           = (1 << 4), // 0x10
    TRACK_SEQUENCE_FLAG_CONNECTS_TO_PATH = (1 << 5), // 0x20
    TRACK_SEQUENCE_FLAG_DISALLOW_DOORS   = (1 << 6), // 0x40
};

enum
{
    TRACK_ELEMENT_LOCATION_IS_UNDERGROUND = 2,
};

enum
{
    GC_SET_MAZE_TRACK_BUILD = 0,
    GC_SET_MAZE_TRACK_MOVE  = 1,
    GC_SET_MAZE_TRACK_FILL  = 2,
};

struct track_circuit_iterator
{
    CoordsXYE       last;
    CoordsXYE       current;
    sint32             currentZ;
    sint32             currentDirection;
    rct_tile_element * first;
    bool               firstIteration;
    bool               looped;
};

extern const rct_trackdefinition FlatRideTrackDefinitions[256];
extern const rct_trackdefinition TrackDefinitions[256];

extern uint8 gTrackGroundFlags;

sint32 track_is_connected_by_shape(rct_tile_element * a, rct_tile_element * b);

const rct_preview_track * get_track_def_from_ride(Ride * ride, sint32 trackType);
const rct_preview_track * get_track_def_from_ride_index(sint32 rideIndex, sint32 trackType);
const rct_track_coordinates * get_track_coord_from_ride(Ride * ride, sint32 trackType);

void track_circuit_iterator_begin(track_circuit_iterator * it, CoordsXYE first);
bool track_circuit_iterator_previous(track_circuit_iterator * it);
bool track_circuit_iterator_next(track_circuit_iterator * it);
bool track_circuit_iterators_match(const track_circuit_iterator * firstIt, const track_circuit_iterator * secondIt);

void track_get_back(CoordsXYE * input, CoordsXYE * output);
void track_get_front(CoordsXYE * input, CoordsXYE * output);

bool track_element_is_block_start(rct_tile_element * trackElement);
bool track_element_is_covered(sint32 trackElementType);
bool track_element_is_station(rct_tile_element * trackElement);
bool track_element_is_lift_hill(const rct_tile_element * trackElement);
void track_element_set_lift_hill(rct_tile_element * trackElement, bool on);
bool track_element_is_cable_lift(const rct_tile_element * trackElement);
void track_element_set_cable_lift(rct_tile_element * trackElement);
void track_element_clear_cable_lift(rct_tile_element * trackElement);
bool track_element_is_inverted(const rct_tile_element * tileElement);
void track_element_set_inverted(rct_tile_element * tileElement, bool inverted);

sint32 track_get_actual_bank(rct_tile_element * tileElement, sint32 bank);
sint32 track_get_actual_bank_2(sint32 rideType, bool isInverted, sint32 bank);
sint32 track_get_actual_bank_3(rct_vehicle * vehicle, rct_tile_element * tileElement);

void game_command_place_track(sint32 * eax, sint32 * ebx, sint32 * ecx, sint32 * edx, sint32 * esi, sint32 * edi, sint32 * ebp);
void game_command_remove_track(sint32 * eax, sint32 * ebx, sint32 * ecx, sint32 * edx, sint32 * esi, sint32 * edi, sint32 * ebp);

void game_command_set_maze_track(sint32 * eax, sint32 * ebx, sint32 * ecx, sint32 * edx, sint32 * esi, sint32 * edi, sint32 * ebp);
money32 maze_set_track(uint16 x, uint16 y, uint16 z, uint8 flags, uint8 direction, uint8 rideIndex, uint8 mode);

void game_command_set_brakes_speed(sint32 * eax, sint32 * ebx, sint32 * ecx, sint32 * edx, sint32 * esi, sint32 * edi, sint32 * ebp);
bool track_element_is_booster(uint8 rideType, uint8 trackType);
bool track_element_has_speed_setting(uint8 trackType);
uint8 track_element_get_seat_rotation(const rct_tile_element * tileElement);
void track_element_set_seat_rotation(rct_tile_element * tileElement, uint8 seatRotation);
uint8 track_element_get_colour_scheme(const rct_tile_element * tileElement);
void track_element_set_colour_scheme(rct_tile_element * tileElement, uint8 colourScheme);
sint32 tile_element_get_station(const rct_tile_element * tileElement);
void tile_element_set_station(rct_tile_element * tileElement, uint32 stationIndex);
sint32 tile_element_get_track_sequence(const rct_tile_element * tileElement);
void tile_element_set_track_sequence(rct_tile_element * tileElement, sint32 trackSequence);
bool tile_element_get_green_light(const rct_tile_element * tileElement);
void tile_element_set_green_light(rct_tile_element * tileElement, bool greenLight);
sint32 tile_element_get_brake_booster_speed(const rct_tile_element *tileElement);
void tile_element_set_brake_booster_speed(rct_tile_element *tileElement, sint32 speed);
bool tile_element_is_taking_photo(const rct_tile_element * tileElement);
void tile_element_set_onride_photo_timeout(rct_tile_element * tileElement);
void tile_element_decrement_onride_photo_timout(rct_tile_element * tileElement);
uint16 track_element_get_maze_entry(const rct_tile_element * tileElement);
uint8 track_element_get_ride_index(const rct_tile_element * tileElement);
void track_element_set_ride_index(rct_tile_element * tileElement, uint8 rideIndex);
uint8 track_element_get_type(const rct_tile_element * tileElement);
void track_element_set_type(rct_tile_element * tileElement, uint8 rideIndex);
