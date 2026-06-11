#include <iostream>
#include <cstring>

using namespace std;
using ll = long long;

#define rep(i,n) for(int i=0;i<(n);++i)
const int MOD = 1e9+7;

int main() {
  int N, M; cin >> N >> M;

  int S[N], T[M];
  rep(i, N) cin >> S[i];
  rep(i, M) cin >> T[i];
  ll dp[N+1][M+1];
  ll sum[N+2][M+2];

  memset(dp, 0, sizeof(dp));
  memset(sum, 0, sizeof(sum));
  int ans = 0;
  dp[0][0] = 1;
  sum[1][1] = 1;
  rep(i, N+1) {
    rep(j, M+1) {
      if (i == 0 && j == 0)
        continue;
      if (i >= 1 && j >= 1 && S[i-1] == T[j-1])
        dp[i][j] = sum[i][j];
      else
        dp[i][j] = 0;

      sum[i+1][j+1] = (sum[i+1][j] + sum[i][j+1] - sum[i][j] + dp[i][j] + MOD) % MOD;
    }
  }
  cout << sum[N+1][M+1] << endl;

  return 0;
}
