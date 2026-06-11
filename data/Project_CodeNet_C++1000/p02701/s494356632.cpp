
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
  u32 n;
  set<string> S;
  cin >> n;
  REP(i, n) {
    string s;
    cin >> s;
    S.insert(s);
  }
  cout << S.size();
  return 0;
}
