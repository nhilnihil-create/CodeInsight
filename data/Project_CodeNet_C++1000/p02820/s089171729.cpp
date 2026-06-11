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

  enum Janken : int64_t { kRock, kSChoki, kPar };
  int64_t N, K, R, S, P;
  cin >> N >> K >> R >> S >> P;
  string T;
  cin >> T;
  const int64_t L = static_cast<int64_t>(T.length());
  int64_t result = 0;
  for (int64_t i = 0; i < K; ++i) {
    vector<vector<int64_t>> dp;
    for (int64_t j = 0; i + j * K < L; ++j) {
      dp.push_back(vector<int64_t>(3, 0));
      const int64_t index = i + j * K;
      Janken enemy;
      if (T.c_str()[index] == 'r') {
        enemy = kRock;
      } else if (T.c_str()[index] == 's') {
        enemy = kSChoki;
      } else {
        enemy = kPar;
      }
      if (j == 0) {
        dp[j][kRock] = (enemy == kSChoki) ? R : 0;
        dp[j][kSChoki] = (enemy == kPar) ? S : 0;
        dp[j][kPar] = (enemy == kRock) ? P : 0;
      } else {
        dp[j][kRock] = max(dp[j - 1][kSChoki], dp[j - 1][kPar]) + ((enemy == kSChoki) ? R : 0);
        dp[j][kSChoki] = max(dp[j - 1][kRock], dp[j - 1][kPar]) + ((enemy == kPar) ? S : 0);
        dp[j][kPar] = max(dp[j - 1][kRock], dp[j - 1][kSChoki]) + ((enemy == kRock) ? P : 0);
      }
    }
    const int64_t len = static_cast<int64_t>(dp.size());
    result += max(dp[len - 1][kRock], max(dp[len - 1][kSChoki], dp[len - 1][kPar]));
  }
  cout << result << endl;

  return 0;
}
