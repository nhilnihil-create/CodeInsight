
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
  i64 n, m;
  cin >> n >> m;

  vector<u32> a(m);

  REP(i, m) {
    u32 ai;
    cin >> ai;
    n -= ai;
  }

  if (n >= 0)
    cout << n;
  else
    cout << -1;

  return 0;
}
