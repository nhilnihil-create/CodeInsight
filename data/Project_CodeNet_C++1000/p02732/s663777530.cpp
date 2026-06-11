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

#define rep(idx, N) for (i32 idx = 0; idx < N; idx++)

int main() {
  i32 n;
  cin >> n;

  unordered_map<i32, i32> a;
  vector<i32> v;
  i32 ai;

  rep(i, n) {
    cin >> ai;
    a[ai] += 1;
    v.push_back(ai);
  }

  unordered_map<i32, u64> c;

  u64 sum = 0;
  for (auto ai : a) {
    c[ai.first] = (u64)(ai.second - 1) * ai.second / 2;
    sum += c[ai.first];
  }

  rep(k, n) {
    u64 ans = 0;

    u64 ai = v[k];
    u64 num = a[ai];
    ans = sum - c[ai] + ((num - 1) * (num - 2)) / 2;

    cout << ans << endl;
  }
  return 0;
}
