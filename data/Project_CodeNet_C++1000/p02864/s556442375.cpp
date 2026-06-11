#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(auto i = 0; i < n; i++)
#define rep1(i, n) for(auto i = 1; i <= n; i++)
#define INF 100000000000
#define ll long long

int N, K, H[305];

int main() {
  cin >> N >> K;
  rep1(i, N) cin >> H[i];
  H[0] = H[N + 1] = 0;
  ll dp[N + 2][N + 1];
  rep(i, N + 2) rep(j, N + 1) dp[i][j] = INF;
  dp[0][0] = 0;
  for(auto i = 0; i <= N + 1; i++) {
    rep(j, i) {
      int p = i - j - 1;
      for(auto s = 0; s + p <= K; s++) {
        dp[i][s + p] = min(dp[i][s + p], dp[j][s] + (H[i] > H[j] ? H[i] - H[j] : 0));
      }
    }
  }
  ll ans = INF;
  rep(i, N + 1) ans = min(ans, dp[N + 1][i]);
  cout << ans << endl;
}