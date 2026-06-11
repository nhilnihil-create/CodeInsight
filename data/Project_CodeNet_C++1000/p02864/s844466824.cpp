#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main() {
  int N, K;
  cin >> N >> K;
  vector<int> H(N);
  for (int i = 0; i < N; i++) {
    cin >> H[i];
  }
  vector<vector<ll>> dp(N, vector<ll>(N + 1, -1));
  for (int i = 0; i < N; i++) {
    dp[i][0] = 0;
    dp[i][1] = H[i];
    for (int j = 2; j <= i + 1; j++) {
      for (int k = j - 2; k < i; k++) {
        if (dp[i][j] == -1) {
          dp[i][j] = dp[k][j - 1] + max(0, H[i] - H[k]);
        } else {
          dp[i][j] = min(dp[i][j], dp[k][j - 1] + max(0, H[i] - H[k]));
        }
      }
    }
  }
  ll res = dp[N - 1][N - K];
  for (int i = 1; i < N; i++) {
    if (dp[i][N - K] != -1)
      res = min(res, dp[i][N - K]);
  }
  cout << res << endl;
  return 0;
}