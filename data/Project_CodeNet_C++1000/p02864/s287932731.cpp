#include <bits/stdc++.h>

#define rep(i, n) for(int (i) = 0; i < (n); ++(i))

typedef long long ll;
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 62;

int main() {
  int N, K;
  std::cin >> N >> K;

  std::vector<ll> H(N + 1);
  rep(i, N) {
    std::cin >> H[i + 1];
  }

  std::vector<std::vector<ll>> dp(N + 1, std::vector<ll>(N + 1, INF));
  for(int i = 0; i <= N; ++i) {
    dp[i][0] = 0;
    dp[i][1] = H[i];
  }
  for(int i = 1; i <= N; ++i) {
    for(int j = 2; j <= i; ++j) {
      for(int t = 1; t < i; ++t) {
        dp[i][j] = std::min(dp[i][j], dp[t][j - 1] + std::max(0LL, H[i] - H[t]));
      }
    }
  }

  ll ans = INF;
  for(int i = 1; i <= N; ++i) {
    ans = std::min(ans, dp[i][N - K]);
  }
  std::cout << ans << '\n';

}
