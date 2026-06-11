#include "bits/stdc++.h"
#include "math.h"
 
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<int> vin;
typedef pair<ll,ll> P;
typedef vector<P> vp;
#define rep(i,a,b) for(ll i=(a);i<(b);++i)
#define drep(i,a,b) for(ll i=(a);i>=(b);--i)
#define SIZE(a) ll((a).size())
#define out(a) cout<<(a)<<endl;
const int inf=INT_MAX;
const int MAX = 510000;
const ll MOD = 998244353;

ll modpow(ll x, ll n){
	ll r=1;
	while(n){
		if(n&1) r=r*x%MOD;
		x=x*x%MOD;
		n>>=1;
	}
	return r;
}

int main(){
  ll n;cin>>n;
  vll d(n),dis(n,0);
  rep(i,0,n){
    cin>>d[i];
    dis[d[i]]++;
  }
  if(dis[0]!=1||d[0]!=0){
    cout<<0<<endl;return 0;
  }
  
  sort(d.begin(),d.end());
  ll ans=1;
  rep(i,1,d[n-1]+1){
    if(dis[i]==0){
      cout<<0<<endl;return 0;
    }
    ans*=modpow(dis[i-1],dis[i]);
    ans%=MOD;
  }
  cout<<ans%MOD<<endl;
}


