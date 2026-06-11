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
  i32 a, b;
  cin >> a >> b;

  for (i32 i = 0; i < 10001; i++) {
    if ((i32)(i * 0.08) == a && (i32)(i * 0.1) == b) {
      cout << i;
      return 0;
    }
  }

  cout << -1;

  return 0;
}
