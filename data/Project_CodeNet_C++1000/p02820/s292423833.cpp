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

  int64_t N, K, Rock, Scissor, Paper;
  string T;
  cin >> N >> K >> Rock >> Scissor >> Paper >> T;

  enum Janken : int32_t { kRock, kScissor, kPaper };
  const int64_t janken[] = {'r', 's', 'p'};
  const int64_t score[] = {Rock, Scissor, Paper};

  int64_t result = 0;
  for (int64_t k = 0; k < K; ++k) {
    vector<vector<int64_t>> dp(N / K + 2, vector<int64_t>(3, 0));
    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[0][2] = 0;
    int64_t last_index = -1;
    for (int64_t i = 1; k + (i - 1) * K < N; ++i) {
      const char enemy = T[k + (i - 1) * K];
      for (int64_t j = kRock; j <= kPaper; ++j) {
        bool win = false;
        if (janken[j] == 'r' && enemy == 's') {
          win = true;
        } else if (janken[j] == 's' && enemy == 'p') {
          win = true;
        } else if (janken[j] == 'p' && enemy == 'r') {
          win = true;
        }
        for (int64_t p = kRock; p <= kPaper; ++p) {
          if (j != p) {
            dp[i][j] = max(dp[i][j], dp[i - 1][p] + (win ? score[j] : 0));
          }
        }
      }
      last_index = i;
    }
    result += max(dp[last_index][0], max(dp[last_index][1], dp[last_index][2]));
  }
  cout << result << endl;
  return 0;
}
