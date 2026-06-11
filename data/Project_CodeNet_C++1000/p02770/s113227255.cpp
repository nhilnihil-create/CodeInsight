#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;
const ll MOD=1e9+7;
const ll N=1e6+4;
const ld pi=3.14159265359;
const ll INF=(1LL<<63);
#define REP(i,n) for(ll i=0;i<n;i++)
#define REP1(i,n) for(ll i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define setp setprecision
#define lwb lower_bound
#define SZ(a) (ll)a.size()

ll n,x,m,d[N],q,ans,k,s;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>k>>q;
	REP(i,k)cin>>d[i];
	while(q--){
		cin>>n>>x>>m;
		ans=n-1;s=0;
		x%=m;
		REP(i,k)s+=(d[i]%m==0?m:d[i]%m),x+=((n-1)%(k)>i?(d[i]%m==0?m:d[i]%m):0);
		cout<<ans-(x+s*((n-1)/k))/m<<"\n";
	}
	return 0;
}
