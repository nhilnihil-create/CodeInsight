/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using Pair = pair<int64_t, int64_t>;

// std::cout << std::setprecision(20) << 1.1 << endl;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int64_t K;
  cin >> K;
  vector<int64_t> result = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  while (true) {
    if (K <= static_cast<int64_t>(result.size())) {
      cout << result[K - 1] << endl;
      break;
    } else {
      K-= static_cast<int64_t>(result.size());
    }
    vector<int64_t> old;
    swap(result, old);
    for (int64_t &v : old) {
      for (int64_t d = -1; d <= 1; ++d) {
        if (v % 10 + d >= 0 && v % 10 + d < 10) {
          result.emplace_back(v * 10 + (v % 10 + d));
        }
      }
    }
  }
  // const int64_t L = static_cast<int64_t>(T.length());
  return 0;
}
