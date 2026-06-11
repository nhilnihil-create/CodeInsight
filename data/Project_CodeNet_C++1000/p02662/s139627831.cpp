#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll N; cin >> N;
  ll S; cin >> S;
  vector<ll> A(N); for (ll i = 0; i < N; i++) cin >> A[i];

  ll MOD = 998244353;
  vector<vector<ll>> dp(N + 1, vector<ll>(S + 1, 0));

  dp[0][0] = 1;
  for (ll i = 0; i < N; i++) {
    for (ll j = 0; j < S + 1; j++) {
      dp[i + 1][j] = (dp[i][j] * 2) % MOD;
      if (j >= A[i]) dp[i + 1][j] = (dp[i + 1][j] + dp[i][j - A[i]]) % MOD;
    }
  }

  cout << dp[N][S] << '\n';
  return 0;
}