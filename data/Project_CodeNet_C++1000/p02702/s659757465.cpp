
#include <bits/stdc++.h>
#include <iostream>
#include <string>

typedef uint64_t u64;
typedef int64_t i64;
typedef uint32_t u32;
typedef int32_t i32;
typedef uint16_t u16;
typedef int16_t i16;
typedef uint8_t u8;
typedef int8_t i8;

using namespace std;

#define REP(idx, N) for (u64 idx = 0; idx < N; idx++)

int main() {
  string s;
  cin >> s;

  map<u32, u32> mods;
  u32 mod = 0;
  u32 mod_dig = 1;

  u32 digit = 0;
  mods[0] = 1;
  for (auto it = --s.end(); it >= s.begin(); it--) {
    u64 m = (*it - '0');
    mod = (mod + m*mod_dig) % 2019;
    mod_dig = mod_dig* 10 % 2019;
    mods[mod] += 1;
    digit++;
  }

  u32 ans = 0;
  for (auto &m : mods) {
    ans += m.second * (m.second - 1) / 2;
  }
  cout << ans;

  return 0;
}
