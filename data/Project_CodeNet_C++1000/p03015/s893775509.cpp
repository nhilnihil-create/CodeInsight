#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int MOD = 1e+9 + 7;

int main() {
  string L;
  cin >> L;

  int N = L.size(), max_d, l;
  vector<vector<vector<ll>>> dp(N + 1, vector<vector<ll>>(2, vector<ll>(2, 0)));
  dp[0][0][0] = 1;
  for (int i = 0; i < N; i++) {
    l = L[i] - '0';
    for (int j = 0; j < 2; j++) {
      max_d = j ? 1 : l;
      for (int d = 0; d <= max_d; d++) {
          dp[i + 1][j || d < l][d] += (dp[i][j][0] + dp[i][j][1]) * (d + 1);
      }
    }
    rep(j, 2) rep(d, 2) {
      dp[i + 1][j][d] %= MOD;
    }
  }
  int ans = 0;
  rep(i, 2) rep(j, 2) {
    ans = (ans + dp[N][i][j]) % MOD;
  }
  cout << ans << endl;
  return 0;
}