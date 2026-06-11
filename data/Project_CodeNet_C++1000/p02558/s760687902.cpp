#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

#define endl "\n"
#define int ll
#define ll long long
#define pb emplace_back
#define fi first
#define se second
#define pll pair<ll, ll>
#define ull unsigned long long
#define ld long double

#define debug(x) cout<<#x<<" :: "<<x<<endl;
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<endl;

#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=n-1; i>=0; i--)
#define repa(i,a,b) for(ll i=(a);i<=(b);i++)
#define all(x) (x).begin(), (x).end()
#define ordered_set tree<int , null_type, less<int> , rb_tree_tag, tree_order_statistics_node_update>
/*
 Ordered set docs:
 order_of_key (k) : Number of items strictly smaller than k .
 find_by_order(k) : K-th element in a set (counting from zero).
*/
#define blc boost::lexical_cast<long long>
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
using namespace __gnu_pbds;
const int MOD = 1e9+7;
const ll INF = 1e18;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll add(ll x, ll y) {ll res=x+y; return(res>=MOD?res-MOD:res);}

ll sub(ll x, ll y) {ll res=x-y; return(res<0?res+MOD:res);}

ll lcm(ll x, ll y) {ll res=(x*y)/__gcd(x,y); return res;}

ll powerLL(ll x, ll n, ll mod) 
{ 
    ll result = 1; 
    while (n) { if (n & 1) result = (result%mod * x%mod) % mod; n = n / 2; x = (x%mod * x%mod) % mod; } return result; 
} 

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const int N = 1e5+5;

struct DSU
{
	int connected;
	vector<int> par, sz;

	void init(int n) 
	{
		par = sz = vector<int> (n + 1, 0);
		for(int i = 1; i <= n; i++)
			par[i] = i, sz[i] = 1;
		connected = n;
	}

	int getPar(int u)
	{
		while(u != par[u])
		{
			par[u] = par[par[u]];
			u = par[u];
		}
		return u;
	}

	int getSize(int u)
	{
		return sz[getPar(u)];
	}

	void unite(int u, int v)
	{
		int par1 = getPar(u), par2 = getPar(v);

		if(par1 == par2)
			return;

		connected--;

		if(sz[par1] > sz[par2])
			swap(par1, par2);

		sz[par2] += sz[par1];
		sz[par1] = 0;
		par[par1] = par[par2];
	}
};

void solve()
{
    ll n, k;
    cin>>n>>k;
    DSU dsu;
    dsu.init(n);
    while(k--)
    {
    	ll a, u, v;
    	cin >> a >> u >> v;
    	u++;
    	v++;
    	if(a == 1)
    	{
    		int val = (dsu.getPar(u) == dsu.getPar(v));
    		cout<< val <<endl;
    	}
    	else
    		dsu.unite(u,v);
    }
}
int32_t main()
{
    fast;
    int t;
    t=1;
    //cin>>t;
    while(t--)
        solve();
    return 0; 
}