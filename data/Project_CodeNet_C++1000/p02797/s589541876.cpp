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

  int64_t N, K, S;
  cin >> N >> K >> S;
  int64_t padding = (S < 1e9L) ? S + 1 : 1;
  for (int64_t i = 0; i < N; ++i) {
    if (i != 0) {
      cout << " ";
    }
    if (i < K) {
      cout << S;
    } else {
      cout << padding;
    }
  }
  cout << endl;
  return 0;
}
