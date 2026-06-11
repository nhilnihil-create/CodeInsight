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
const int INF = 0x3f3f3f3f, N = 505;
const ll LINF = 1e18 + 5;
int n, k, h[N];
ll dp[N][N];
int main()
{
 	ios::sync_with_stdio(false);
 	cin.tie(0);
 	cin >> n >> k;
 	for(int i=1;i<=n;i++) cin >> h[i];
 	for(int i=0;i<=n;i++)
 		for(int j=0;j<=i;j++)
 			dp[i][j] = LINF;
 	dp[0][0] = 0;
 	for(int i=1;i<=n;i++)
 		for(int j=1;j<=i;j++)
 			for(int t=j-1;t<i;t++)
 				dp[i][j] = min(dp[i][j],dp[t][j-1]+max(0,h[i]-h[t]));
 	ll ans = LINF;
 	for(int i=n-k;i<=n;i++)
 			ans = min(ans,dp[i][n-k]); 
  	cout << ans;
	return 0;
}
