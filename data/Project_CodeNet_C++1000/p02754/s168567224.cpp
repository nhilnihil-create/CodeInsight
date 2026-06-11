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
  i64 n, a, b;
  cin >> n >> a >> b;

  u64 ans = 0;
  ans = n / (a + b) * a;

  i64 d = (n % (a + b));

  ans += min(a, d);

  cout << ans;

  return 0;
}
