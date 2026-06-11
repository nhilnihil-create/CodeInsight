#include<bits/stdc++.h>
using namespace std;
const int maxn=100 + 2e3;
const long long mod = 1e9 + 7;

typedef pair<int,int> II;

int n, m, a[maxn], b[maxn];
long long dp[maxn][maxn];

int main()
{

//	freopen("abc.inp","r",stdin);freopen("abc.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie();
	cout.tie();

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= m; ++i) {
		cin >> b[i];
	}
	for (int i = 0; i <= max(n, m); ++i) dp[0][i] = dp[i][0] = 1;
  for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			dp[i][j] = ((dp[i-1][j] + dp[i][j-1]) % mod - dp[i-1][j-1] + mod) % mod;
      if (a[i] == b[j]) {
        dp[i][j] += (dp[i-1][j-1]);
        dp[i][j] %= mod;
      }

		}
  }

	cout<<dp[n][m];


   return 0;
}
