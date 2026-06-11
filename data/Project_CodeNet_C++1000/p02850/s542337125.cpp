#include <bits/stdc++.h>
using namespace std;
 
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long double ld;
 
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;
 
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 3;
 
#define _  %  MOD
#define __ %= MOD
 
#define      each(it,s)        for(auto it = s.begin(); it != s.end(); ++it)
#define      sortA(v)          sort(v.begin(), v.end())
#define      sortD(v)          sort(v.begin(), v.end(), greater<auto>())
#define      fill(a)           memset(a, 0, sizeof (a))
 
#define      swap(a,b)        {a=a+b;b=a-b;a=a-b;}
#define      rep(i, n)         for(ll i = 0; i < (n); ++i)
#define      repA(i, a, n)     for(ll i = a; i <= (n); ++i)
#define      repD(i, a, n)     for(ll i = a; i >= (n); --i)
#define watch(x) cout << (#x) << " is " << (x) <<endl
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
#define fbo find_by_order
#define ook order_of_key
 
ll gcd(ll a,ll b){if(b==0) return a; else return gcd(b,a%b);}
ll power(ll x,ll y){ll res=1; while(y>0){if(y&1) res=res*x;y=y>>1;x=x*x;}return res;} // modular exponent
ll n;
ll ans=0;
const int N=1e5+5;
vector<ll> adj[N];
map<pair<ll,ll>,ll> m;
map<ll,ll> clr;
void dfs(ll u,ll par,ll parcol)
{
	ll childcol=(parcol+1)%ans;
	pair<ll,ll> edge=mp(min(u,par),max(u,par));
	clr[m[edge]]=childcol;
	for(auto v:adj[u])
	{
		if(v==par) continue;
		dfs(v,u,childcol);
		childcol=(childcol+1)%ans;
	}
	return ;
}
int main()
{
    ios_base::sync_with_stdio(false); // don't use printf and scanf
    cin.tie(NULL); // cout<<fixed<<setprecision
	cin>>n;
	m[mp(0ll,1ll)]=0ll;
	repA(i,1,n-1)
	{
		ll x,y;
		cin>>x>>y;
		if(x>y) swap(x,y);
		m[mp(x,y)]=i;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	repA(i,1,n) ans=max(ans,(ll)adj[i].size());
	cout<<ans<<'\n';
	dfs(1,0,-1);
	for(auto it:clr)
	{
		if(it.fi==0) continue;
		cout<<it.se+1<<'\n';
	}
	return 0;
}
// JUST ASK YOURSELF DID YOU GIVE YOUR BEST ? ISSE ZYADA
// KUCH KAR BHI NAHI SAKTE !! ENJOY AND GIVE YOUR BEST!!

