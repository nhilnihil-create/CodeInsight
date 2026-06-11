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
    vector<int64_t> dp(3, 0);
    for (int64_t i = 1; k + (i - 1) * K < N; ++i) {
      const char enemy = T[k + (i - 1) * K];
      vector<int64_t> prev(3, 0);
      swap(dp, prev);
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
            dp[j] = max(dp[j], prev[p] + (win ? score[j] : 0));
          }
        }
      }
    }
    result += max(dp[0], max(dp[1], dp[2]));
  }
  cout << result << endl;
  return 0;
}
