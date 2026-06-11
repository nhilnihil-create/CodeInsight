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

  int64_t N, K, R, S, P;
  cin >> N >> K >> R >> S >> P;
  string T;
  cin >> T;
  const int64_t L = static_cast<int64_t>(T.length());
  int64_t result = 0;
  for (int64_t i = 0; i < K; ++i) {
    vector<vector<int64_t>> dp;
    for (int64_t j = 0; i + j * K < L; ++j) {
      dp.push_back(vector<int64_t>(2, 0));
      const int64_t index = i + j * K;
      int64_t win;
      if (T.c_str()[index] == 'r') {
        win = P;
      } else if (T.c_str()[index] == 's') {
        win = R;
      } else {
        win = S;
      }
      if (j == 0) {
        dp[j][0] = 0;
        dp[j][1] = win;
      } else {
        dp[j][0] = dp[j - 1][1];
        dp[j][1] = dp[j - 1][0] + win;
        if (T.c_str()[index] != T.c_str()[index - K]) {
          dp[j][1] = max(dp[j][1], dp[j - 1][1] + win);
        }
      }
    }
    const int64_t len = static_cast<int64_t>(dp.size());
    result += max(dp[len - 1][0], dp[len - 1][1]);
  }
  cout << result << endl;

  return 0;
}
