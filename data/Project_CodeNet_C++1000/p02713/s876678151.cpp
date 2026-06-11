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

int main() {
  i32 k;
  cin >> k;

  u64 ans = 0;
  rep(a, k) {
    rep(b, k) {
      rep(c, k) { ans += gcd(a+1, gcd(b+1, c+1)); }
    }
  }

  cout << ans << endl;

  return 0;
}
