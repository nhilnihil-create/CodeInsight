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
int dp[2005][2005];
signed main()
{
//	freopen(".inp", "r", stdin);
//	freopen(".out", "w", stdout);
	int n;
	cin>>n;
	vii v;
	for(int i=1; i<=n; i++)
	{
		int t;
		cin>>t;
		v.eb(t, i);
	}
	sort(begin(v), end(v));
	reverse(begin(v), end(v));
	dp[0][n+1]=0; 
	int ans=0;
	for(int i=0; i<=n; i++)
	{
		for(int l=0; l<=i; l++)
		{
			int r=n+1-(i-l);
			if(l<r-1)
			{
				dp[l+1][r]=max(dp[l+1][r], dp[l][r]+abs(l+1-v[i].se)*v[i].fi);
				dp[l][r-1]=max(dp[l][r-1], dp[l][r]+abs(r-1-v[i].se)*v[i].fi);
			}
			else ans=max(ans, dp[l][r]);
		}
	}
	cout<<ans;
}


