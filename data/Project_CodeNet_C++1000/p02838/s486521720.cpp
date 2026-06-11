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
#define SIZE(a) int((a).size())
#define out(a) cout<<(a)<<endl;
const int INF=INT_MAX;
const int MAX = 510000;
const ll MOD = 1000000007;
ll roundd(ll x,ll n){
  if(x>n){return x%n;}
  else if(x<0){return x%n+n;}
  else return x;
}
bool isprime(ll n){
    if(n==1)return false;
    for (ll i = 2; i * i <= n; i++) {
        if(n%i==0)return false;
    }
    return true;
}

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
  vll a(n);vvll cnt(60,vll(2,0));
  rep(i,0,n){
    cin>>a[i];
  }
  rep(i,0,n){
    rep(j,0,60){
      if(a[i]>>j&1)cnt[j][1]++;
      else cnt[j][0]++;
    }
  }
  ll ans=0;
  rep(i,0,60){
    cnt[i][0]%=MOD;cnt[i][1]%=MOD;
    ans+=(modpow(2,i)*((cnt[i][0]*cnt[i][1])%MOD))%MOD;
    ans%=MOD;
  }
  cout<<ans<<endl;
}

