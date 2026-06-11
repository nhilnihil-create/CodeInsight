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

string BinToString(ll x)
{
	string res;
	for(int i=8;i>=0;i--){
		if((1LL<<i)&x) res+='1';
		else res+='0';
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n; cin>>n;
	vii a[n];
	forn(i,0,n){
		int m; cin>>m;
		forn(j,0,m){
			int u,v; cin>>u>>v; u--;
			a[i].pb({u,v});
		}
	}
	
	int ans=0;
	for(int mask=0;mask<(1<<n);mask++){
		bool ok=1;
		forn(i,0,n){
			if((mask&(1<<i))==0) continue;
			for(ii tmp: a[i]){
				int u=tmp.F, v=tmp.S;
				if(bool((1<<u)&mask)!=v){ ok=0; break; }
			}
		}
		
		if(ok){
			ans=max(ans, __builtin_popcount(mask));
			//cout<<"mask="<<BinToString(mask)<<'\n';
		}
	}
	
	cout<<ans<<'\n';
	
	return 0;
}
