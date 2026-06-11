//	ZapZu's code hohoho
//	#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
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
int a[55][1000005];
int dp[1000005];
signed main()
{
//	freopen(".inp", "r", stdin);
//	freopen(".out", "w", stdout);
	int n;
	cin>>n;
	vi v;
	for(int i=1; i<=n; i++)
	{
		char c;
		cin>>c;
		a[1][i]=c-'0';
		dp[i]=dp[i-1];
		int temp=i;
		while(temp%2==0) temp/=2, dp[i]++;
	}
	for(int i=2; i<=min(n, 50); i++)
	{
		for(int j=1; j<=n+1-i; j++)
		{
			a[i][j]=abs(a[i-1][j]-a[i-1][j+1]);
			if(i==50) v.eb(a[i][j]);
		}
	}
	if(n<=50) cout<<a[n][1];
	else 
	{
		n=v.size()-1;
		int ans=0;
		for(int i=0; i<=n; i++)
		{
//			cout<<v[i]<<" ";
			if(dp[i]+dp[n-i]<dp[n]) continue;
			ans^=v[i];
		}
		cout<<ans;
	}
	
}


