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
  string si, s;
  cin >> si;

  s = si;

  string s2 = s;
  reverse(s.begin(), s.end());

  if (s != s2) {
    cout << "No" << endl;
    return 0;
  }

  i32 n = si.length();
  s = si.substr(0, (n - 1) / 2);
  s2 = s;
  reverse(s2.begin(), s2.end());

  if (s != s2) {
    cout << "No" << endl;
    return 0;
  }

  s = si.substr((n + 3) / 2 - 1, n);
  s2 = s;
  reverse(s2.begin(), s2.end());
  if (s != s2) {
    cout << "No" << endl;
    return 0;
  }

  cout << "Yes" << endl;

  return 0;
}
