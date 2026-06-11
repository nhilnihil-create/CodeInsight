#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define debug(x) cerr << #x << " " << x << '\n'
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pli = pair<ll,int>;
const int INF = 0x3f3f3f3f, N = 2e3 + 5;
const ll LINF = 1e18 + 5;
const int mod = 1e9 + 7;
int s[N], t[N];
int n, m;
ll dp[N][N], sum[N][N];
int main()
{
 	ios::sync_with_stdio(false);
 	cin.tie(0);
 	cin >> n >> m;
 	for(int i=1; i<=n; i++) cin >> s[i];
 	for(int i=1; i<=m; i++) cin >> t[i];
 	dp[0][0] = 1;
 	for(int i=0; i<=n; i++) sum[i][0] = 1;
	for(int i=0; i<=m; i++) sum[0][i] = 1; 
 	for(int i=1; i<=n; i++)
 	{
 		for(int j=1; j<=m; j++)
 		{
 			if(s[i]==t[j]) (dp[i][j] += sum[i-1][j-1])%=mod;
 			(sum[i][j] += (sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1]+dp[i][j])%mod)%=mod;
 		}
 	}
 	ll ans = sum[n][m];
 	ans = (ans + mod)%mod;
 	cout << ans;
	return 0;
}