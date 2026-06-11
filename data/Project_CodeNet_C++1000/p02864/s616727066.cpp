#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
constexpr ll INF = 1LL << 60;

int main() {
  ll N, K; cin >> N >> K;
  vector<ll> H(N+1);
  H[0] = 0;
  for(int i = 1; i <= N; ++i) cin >> H[i];
  if(N == K) {
    cout << 0; return 0;
  }

  vector<vector<ll>> dp(N+1, vector<ll>(N+1, INF));
  dp[0][0] = 0;
  for(int i = 1; i <= N; ++i)
    for(int j = 1; j <= N; ++j)
      for(int k = 0; k < i; ++k) dp[i][j] = min(dp[i][j], dp[k][j-1] + max(0LL, H[i] - H[k]));

  ll ans = INF;
  for(int i = 1; i <= N; ++i) ans = min(ans, dp[i][N - K]);
  cout << ans;
  return 0;
}