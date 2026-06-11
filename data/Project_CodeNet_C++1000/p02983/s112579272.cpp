/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <bits/stdc++.h>
using namespace std;
using Pair = pair<int64_t, int64_t>;
constexpr int64_t kInf = INT64_MAX / 2L;

// std::cout << std::setprecision(20) << 1.1 << endl;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int64_t L, R;
  cin >> L >> R;
  int64_t result = kInf;
  if ((R - L >= 2019) || (L % 2019) >= (R % 2019)) {
    result = 0;
  } else {
    R %= 2019;
    L %= 2019;
    for (int64_t i = L; i <= R; ++i) {
      for (int64_t j = i + 1; j <= R; ++j) {
        result = min(result, ((i * j) % 2019));
      }
    }
  }
  cout << result << endl;
  return 0;
}
