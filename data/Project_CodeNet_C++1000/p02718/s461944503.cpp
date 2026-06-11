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

  i64 v[101] = {0};

  i64 n, m;
  cin >> n >> m;

  i64 sum = 0;
  rep(i, n) {
    i64 ai;
    cin >> ai;
    v[i] = ai;
    sum += ai;
  }

  i64 ans = 0;
  rep(i, n) {
    if (v[i] >= 1.0 * sum / (4.0 * m)) {
      ans++;
    }
  }

  if (ans >= m) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
