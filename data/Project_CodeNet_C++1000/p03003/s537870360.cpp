//	ZapZu's code hohoho
//	#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define dfs_black 1
#define dfs_white -1
#define pr pair
#define vt vector
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

typedef double db;
typedef long long li;
typedef long double ld;

typedef pr<int, int> ii;
typedef pr<ld,ld> dd;

typedef vt<int> vi;
typedef vt<li> vli;
typedef vt<ld> vld;
typedef vt<ii> vii;

typedef map<int, int> mii;
typedef map<int, bool> mib;
typedef map<int, char> mic;

typedef set<int> s_i;
typedef set<char> s_c;

const int MOD = 1e9+7;
const li INF = 1e18;
const ld PI = 4*atan((ld)1);
int s[2005], t[2005];
li dp[2005][2005];
signed main()
{
//	freopen(".inp", "r", stdin);
//	freopen(".out", "w", stdout);
	int n, m;
	cin>>n>>m;
	dp[0][0]=1;
	for(int i=1; i<=n; i++)
	{
		cin>>s[i];
		dp[i][0]=1;
	}
	for(int j=1; j<=m; j++)
	{
		cin>>t[j];
		dp[0][j]=1;
	}
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
		{
			if(s[i]==t[j]) dp[i][j]=(dp[i-1][j]+dp[i][j-1])%MOD;
			else dp[i][j]=(dp[i][j-1]+dp[i-1][j]-dp[i-1][j-1]+MOD)%MOD;
//			cout<<i<<" "<<j<<dp[i][j]<<endl;
		}
	}
//	for(int i=0;i<=n;i++)
//	{
//		for(int j=0;j<=m;j++)
//		{
//			cout<<dp[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	cout<<dp[n][m];
}
