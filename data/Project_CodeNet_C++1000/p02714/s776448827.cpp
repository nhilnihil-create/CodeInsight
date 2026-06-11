#include <bits/stdc++.h>

typedef uint64_t u64;
typedef int64_t i64;
typedef uint32_t u32;
typedef int32_t i32;
typedef uint16_t u16;
typedef int16_t i16;
typedef uint8_t u8;
typedef int8_t i8;

using namespace std;

#define rep(idx, N) for (u64 idx = 0; idx < N; idx++)

i32 toBit(char c) {
  if (c == 'R') {
    return 1;
  } else if (c == 'G') {
    return 2;
  } else {
    return 4;
  }
}

int main() {
  i32 n;
  string s;
  cin >> n >> s;

  map<u32, u32> color;

  u64 ans = 0;
  rep(i, n) {
    auto c = toBit(s.at(i));
    auto find = c ^ 7;

    if (i >= 2) {

      u64 inc = 1;
      for (int j = 1; j <= 4; j *= 2) {
        if (j != c) {
          inc *= color[j];
        }
      }

      ans += inc;

      for (int j = i - 1; j>0 && j - ((i32)i - j) >= 0; j--) {
        if ((toBit(s[i]) | toBit(s[j]) | toBit(s.at(j - (i - j)))) == 0b111) {
          ans--;
        }
      }
    }

    color[c] += 1;
  }

  cout << ans;

  return 0;
}
