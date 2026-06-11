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
  u64 n, k;
  cin >> n >> k;

  vector<u64> p(n);
  deque<double> e(k);

  rep(i, n) { cin >> p[i]; }

  double ans = 0.0;
  double ex = 0.0;

  rep(i, k) {
    e[i] = (1.0 + p[i]) * p[i] / 2.0 / p[i];
    ex += e[i];
  }

  ans = ex;

  rep(i, n - k) {
    ex -= e.front();
    e.pop_front();
    e.push_back((1.0 + p[i + k]) * p[i + k] / 2.0 / p[i + k]);
    ex += e.back();

    if (ex > ans) {
      ans = ex;
    }
  }

  printf("%.7lf\n", ans);

  return 0;
}
