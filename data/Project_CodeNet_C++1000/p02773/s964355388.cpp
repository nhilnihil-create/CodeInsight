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
  u32 n;
  map<string, u32> s;

  cin >> n;
  u32 max = 0;
  rep(i, n) {
    string si;
    cin >> si;
    s[si] += 1;
    if (s[si] > max) {
      max = s[si];
    }
  }

  for (auto &si : s) {
    if (si.second == max) {
      cout << si.first << endl;
    }
  }

  return 0;
}
