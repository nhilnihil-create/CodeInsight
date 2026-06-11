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
const int MOD = 1e9+7;

ll add(ll a,ll b)
{
	a%=MOD; b%=MOD;
	a+=b;a%=MOD;
	if(a<0) a+=MOD;
	return a;
}

const int MAXN = 100005;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n,m; cin>>n>>m;
	set<int> s;
	forn(i,0,m){ int x; cin>>x; s.insert(x); }
	
	ll dp[n+1]{};
	dp[0]=1;
	fore(i,1,n){
		if(s.count(i)) continue;
		dp[i]=add(dp[i-1],dp[i]);
		if(i-2>=0) dp[i]=add(dp[i-2],dp[i]);
	}
	
	cout<<dp[n]<<'\n';
	
	return 0;
}
