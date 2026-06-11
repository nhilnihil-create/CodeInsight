#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=1LL<<61;

ll mpow(ll x, ll n) {
  ll ans=1;
  while(n>0) {
    if(n&1) {
      ans=ans*x%mod;
    }
    x=x*x%mod;
    n>>=1;
  }
  return ans;
}

int main() {
  ll n,k;
  cin >> n >> k;
  vec c(k+1);
  ll ans=0;
  for(ll i=k;i;i--) {
    c[i]=mpow(k/i,n);
    for(ll j=2;j*i<=k;j++) {
      c[i]=(c[i]-c[j*i]+mod)%mod;
    }
    (ans+=c[i]*i)%=mod;
  }
  cout << ans << endl;
}