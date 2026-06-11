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

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n,K; cin>>n>>K;
	ll a[3]{}; forn(i,0,3) cin>>a[i];
	string s; cin>>s;
	
	bool skipped[n]{};
	
	ll ans=0;
	forn(i,0,n){
		if(s[i]=='r') ans+=a[2];
		if(s[i]=='s') ans+=a[0];
		if(s[i]=='p') ans+=a[1];
		if(i-K>=0 && s[i]==s[i-K] && !skipped[i-K]){
			if(s[i]=='r') ans-=a[2];
			if(s[i]=='s') ans-=a[0];
			if(s[i]=='p') ans-=a[1];
			skipped[i]=1;
		}
	}
	
	cout<<ans<<'\n';
	
	return 0;
}
