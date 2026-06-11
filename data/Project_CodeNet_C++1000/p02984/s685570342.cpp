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
	
	int n; cin>>n;
	ll a[n],sum=0;
	ll b[n]{};
	
	forn(i,0,n){
		cin>>a[i]; sum+=a[i];
	}
	
	sum/=2;
	b[0]=sum;
	for(int i=2;i<n;i+=2){
		b[0]-=a[i];
	}
	
	forn(i,1,n){
		b[i]=a[i]-b[i-1];
	}
	
	cout<<b[n-1]*2<<" ";
	forn(i,0,n-1) cout<<b[i]*2<<" ";
	
	return 0;
}
