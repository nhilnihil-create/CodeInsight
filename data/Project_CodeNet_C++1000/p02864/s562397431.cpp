#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main() {
  int N, K;
  cin >> N >> K;
  vector<LL> H(N + 1, 0);
  for (int i = 0; i < N; i++) {
    cin >> H[i + 1];
  }
  H.push_back(0);

  LL INF = 1LL << 60;
  vector<vector<LL>> dp(N + 2, vector<LL>(N + 2, INF));
  dp[0][0] = 0;
  for (int i = 0; i < N + 1; i++) {
    for (int k = 0; k <= K; k++) {
      // dp[i+1][k] = ...
      for (int j = 0; j <= k; j++) {
        if (i - j < 0) continue;
        if (k - j < 0) continue;
        dp[i + 1][k] =
            min(dp[i + 1][k], dp[i - j][k - j] + abs(H[i + 1] - H[i - j]));
      }
    }
    // for (int k = 0; k <= K; k++) cout << dp[i + 1][k] << " ";
    // cout << endl;
  }
  LL ans = INF;
  for (int k = 0; k <= K; k++) {
    ans = min(ans, dp[N + 1][k]);
  }
  cout << ans / 2 << endl;

  return 0;
}
