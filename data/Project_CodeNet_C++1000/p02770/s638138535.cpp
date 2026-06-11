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
int a[200005];
int b[200005];
signed main()
{
//	freopen(".inp", "r", stdin);
//	freopen(".out", "w", stdout);
	int k, q;
	cin>>k>>q;
	for(int i=0; i<k; i++)
	{
		cin>>a[i];
	}
	while(q--)
	{
		int n, x, m, c_sum=0, c_cnt=0;
		cin>>n>>x>>m; x%=m; n--;
		for(int i=0; i<k; i++)
		{
			b[i]=a[i]%m;
			if(!b[i]) b[i]=m;
			c_sum+=b[i];
		}
		int c_num=n/k, l_num=n%k, ans=0;
		x+=c_sum*c_num;
		for(int i=0; i<l_num; i++)
		{
			x+=b[i];
		}
		ans=x/m;
		cout<<n-ans<<endl;
	}
}


