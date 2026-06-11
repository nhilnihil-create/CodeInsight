#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxN = 2e3 + 10;
const ll mod = 1e9 + 7;

ll dp[maxN][maxN];
int a[maxN], b[maxN];
int n, m;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(NULL);
//  freopen("abc.inp", "r", stdin); freopen("abc.out", "w", stdout);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= m; ++i) {
    cin >> b[i];
  }
  for (int i = 0; i <= n; ++i) dp[i][0] = 1;
  for (int j = 0; j <= m; ++j) dp[0][j] = 1;

  for (int i = 1; i <= n; ++i)
  for (int j = 1; j <= m; ++j) {
    dp[i][j] = (dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + mod) % mod;

    if (a[i] == b[j]) {
      dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % mod;
    }
  }
  cout << dp[n][m];
return 0;
}
