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
  string s, t, u;
  u64 a, b;
  cin >> s >> t >> a >> b >> u;

  if (s == u) {
    printf("%d %d\n", a - 1, b);
  } else if (u == t) {
    printf("%d %d\n", a, b - 1);
  }

  return 0;
}
