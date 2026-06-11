#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define watch(x) cout<<(#x)<<"="<<(x)<<'\n'
#define mset(d,val) memset(d,val,sizeof(d))
#define setp(x) cout<<fixed<<setprecision(x)
#define forn(i,a,b) for(int i=(a);i<(b);i++)
#define fore(i,a,b) for(int i=(a);i<=(b);i++)
#define pb push_back
#define F first
#define S second
#define pqueue priority_queue
#define fbo find_by_order
#define ook order_of_key
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef long double ld;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
void amin(ll &a, ll b){ a=min(a,b); }
void amax(ll &a, ll b){ a=max(a,b); }
void SD(int t=0){ cout<<"PASSED "<<t<<endl; }
const ll INF = ll(1e18);
const int MOD = 998244353;

const int MAXN = 100005;

int n;
vii adj[MAXN];
int clr[MAXN];
ll Max=0;

void dfs(int u, int p, int c){
	//watch(u);
	for(ii tmp: adj[u]){
		int v=tmp.F, e=tmp.S;
		if(v==p) continue;
		clr[e]=c;
		
		c++;
		c%=Max;
		dfs(v,u,c);
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin>>n;
	forn(i,0,n-1){
		int u,v; cin>>u>>v; u--; v--;
		adj[u].pb({v,i});
		adj[v].pb({u,i});
	}
	
	forn(i,0,n) Max=max(Max, (ll)adj[i].size());
	
	dfs(0,-1,0);
	
	cout<<Max<<'\n';
	forn(i,0,n-1){
		cout<<clr[i]+1<<'\n';
	}
	
	return 0;
}
