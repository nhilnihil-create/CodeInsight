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

  int64_t N, K;
  string S;
  cin >> N >> K >> S;
  int64_t neq = 0;
  for (int64_t i = 0; i <= N - 2; ++i) {
    if (S[i] != S[i + 1]) {
      ++neq;
    }
  }
  neq -= min(neq, K * 2);
  const int64_t result = (N - 1) - neq;
  cout << result << endl;
  return 0;
}
