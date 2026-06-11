#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;
const ll MOD=1e9+7;
const ll N=3e5+5;
const ld pi=3.14159265359;
#define REP(i,n) for(ll i=0;i<n;i++)
#define REP1(i,n) for(ll i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define setp setprecision
#define lwb lower_bound
#define SZ(a) (ll)a.size()

ll n,x,cnt[N],p[N],ans[N],rans[N];
vector<ll> v;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	REP(i,n){cin>>x;cnt[x]++;}
	REP1(i,n)v.pb(cnt[i]);
	sort(v.begin(),v.end());
	REP(i,n)p[i]=(i?p[i-1]:0)+v[i];
	for(ll m=n;m>=1;m--){
		ll id=lwb(v.begin(),v.end(),m)-v.begin();
		ans[m]=(n-id+p[id-1]/m);
	}
	REP1(i,n){rans[ans[i]]=i;}
	for(ll i=n-1;i>=1;i--)rans[i]=max(rans[i+1],rans[i]);
	REP1(i,n)cout<<rans[i]<<"\n";	
	return 0;
}


