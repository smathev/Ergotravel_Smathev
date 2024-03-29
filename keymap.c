﻿#include QMK_KEYBOARD_H
#include "keymap_nordic.h"
#include "keymap_swedish.h"

extern keymap_config_t keymap_config;


#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16


#define RALT_0 RALT(KC_0)
#define LSFT_1 LSFT(KC_8)
#define RALT_2 RALT(KC_2)
#define RALT_3 RALT(KC_3)
#define RALT_4 RALT(KC_4)
#define RALT_5 RALT(KC_5)
#define LSFT_7 LSFT(KC_7)
#define RALT_7 RALT(KC_7)
#define RALT_8 RALT(KC_8)
#define RALT_9 RALT(KC_9)

#define ALT_CL LALT(KC_F4)
#define KC_ KC_TRNS

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};





enum my_keycodes {
//Tap Dance Declarations
  TD_Win_Exp= 0,

 // Macros
  KC_CCCV,
  MY_CUSTOM_MACRO,
  MAC_CLOSEWINDOW
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {

  [TD_Win_Exp]  = ACTION_TAP_DANCE_DOUBLE(KC_LGUI, LGUI(KC_E)),

};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //,--------+--------+--------+--------+--------+--------+--------.        ,--------+--------+--------+--------+--------+--------+--------.
     KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_BSPC,          KC_VOLU,   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,   KC_BSPC,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_ENT,           KC_VOLD,      KC_H,    KC_J,    KC_K,    KC_L,    NO_AA,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_PGDOWN,         KC_PGUP,      KC_N,    KC_M,  NO_OSLH,   NO_AE,  KC_LEFT, KC_UP,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     KC_LCTL, TD(TD_Win_Exp), NO_ALGR, KC_LALT, LT(_LOWER, KC_COMM), KC_SPC, KC_SPC, LT(_RAISE, KC_COMM), KC_DOT, NO_MINS, KC_DOWN, KC_RGHT
  //`--------+--------+--------+--------+--------+--------+--------/        \--------+--------+--------+--------+--------+--------+--------'
  ),

  [_LOWER] = LAYOUT(
  //,--------+--------+--------+--------+--------+--------+--------.        ,--------+--------+--------+--------+--------+--------+--------.
     KC_ESC,  KC_1,    KC_PGUP,  KC_UP,   KC_4,    KC_5,    KC_DEL,          KC_B,    NO_MINS,  KC_7,   KC_8,    KC_9,    NO_ACUT, KC_DEL,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     KC_TAB,  KC_HOME, KC_LEFT,  KC_DOWN, KC_RGHT, KC_END, KC_,               KC_D,    NO_PLUS,  KC_4, KC_5,    KC_6,    NO_QUOT, KC_PIPE,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     KC_LSFT, NO_LESS, KC_PGDN,   KC_F9,   KC_F10,  KC_F11,  KC_F12,         KC_SPC,  KC_N,    KC_1,  KC_2,    KC_3,    NO_APOS, KC_ENT,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     KC_,     KC_,      KC_,    KC_,     KC_,               KC_,             LT(_ADJUST, KC_SPC),              KC_,    KC_0,    NO_SLSH, KC_DOWN, NO_PLUS
  //`--------+--------+--------+--------+--------+--------+--------/        \--------+--------+--------+--------+--------+--------+--------'
  ),

  [_RAISE] = LAYOUT(
  //,--------+--------+--------+--------+--------+--------+--------.        ,--------+--------+--------+--------+--------+--------+--------.
     KC_ESC,  ALT_CL,    KC_7,    KC_3,    KC_4,    KC_5,    KC_A,             KC_B,    KC_6,    RALT_7,    RALT_8,    RALT_9,    KC_0,    KC_BSPC,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_C,             KC_D,    KC_Y,    RALT_4,    RALT_5,    LSFT_7,    KC_P,    KC_DEL,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_A,             KC_SPC,  KC_N,    LSFT_1,    RALT_2,    RALT_3,    KC_X,   KC_ENT,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     KC_,     KC_,    KC_,      KC_,     KC_,               LT(_ADJUST, KC_SPC),             LT(_ADJUST, KC_SPC),               KC_,     RALT_0, KC_UP,   KC_DOWN, KC_RCTL
  //`--------+--------+--------+--------+--------+--------+--------/        \--------+--------+--------+--------+--------+--------+--------'
  ),

  [_ADJUST] = LAYOUT(
  //,--------+--------+--------+--------+--------+--------+--------.        ,--------+--------+--------+--------+--------+--------+--------.
     KC_ESC,  RESET,   KC_3,   KC_F3,   KC_F4,   KC_F5,   KC_F6,            KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_C,             KC_D,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_A,             KC_SPC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     KC_, KC_, KC_, KC_,          KC_, KC_,          KC_, KC_,            KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT
  //`--------+--------+--------+--------+--------+--------+--------/        \--------+--------+--------+--------+--------+--------+--------'
  )

};



bool process_record_user(uint16_t keycode, keyrecord_t *record) {
static uint16_t code_timer;

switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
    case KC_CCCV:                                  
     if(record->event.pressed){
       code_timer= timer_read();
     } else {
       if (timer_elapsed(code_timer) > TAPPING_TERM) {   // Hold, copy
         SEND_STRING(SS_LALT("7") SS_LALT("0") SS_TAP(X_LEFT));
       } else { 
         SEND_STRING(SS_LALT("7"));
       }
     }
    return false;
    break;
    case MAC_CLOSEWINDOW:                                  
     if(record->event.pressed){
       code_timer= timer_read();
     } else {
       if (timer_elapsed(code_timer) > TAPPING_TERM) {   // Hold, copy
         SEND_STRING(SS_LALT(SS_TAP(F4)));
       } 
     }
    return false;
    break;
  }
  return true;
}



