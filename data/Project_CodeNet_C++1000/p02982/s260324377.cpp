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

i32 x[10][10];

int main() {
  i32 n, d;
  cin >> n >> d;

  rep(i, n) rep(j, d) cin >> x[i][j];

  u32 ans = 0;
  rep(j, n) {
    rep(i, j) {
      u32 sumsq = 0;
      rep(k, d) { sumsq += (x[j][k] - x[i][k]) * (x[j][k] - x[i][k]); }
      u32 sq = sqrt(sumsq) + 0.5;
      if (sumsq == sq * sq)
        ans++;
    }
  }

  cout << ans << endl;

  return 0;
}
