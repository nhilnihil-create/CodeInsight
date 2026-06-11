#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using  namespace std;
typedef long long ll;

const int MAXN = 2005;
const ll Mod = 1e9+7;
ll dp[MAXN][MAXN];
int N, M;
int S[MAXN], T[MAXN];

void solve() {
  for (int i = N-1; i >= 0; --i) {
    for (int j = M-1; j >= 0; --j) {
      dp[i][j] += dp[i+1][j] + dp[i][j+1] - dp[i+1][j+1];
      dp[i][j] = (dp[i][j] + Mod) % Mod;
      if (S[i] == T[j]) dp[i][j] += dp[i+1][j+1] + 1;
      dp[i][j] %= Mod;
    }
  }
  ll ans = (dp[0][0]+1) % Mod;
  cout << ans << endl;
}

int main() {
  cin >> N >> M;
  rep(i, N) cin >> S[i];
  rep(i, M) cin >> T[i];
  solve();
  return 0;
}