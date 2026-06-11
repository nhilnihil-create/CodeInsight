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

vec tfact(1e7+1);
void fact(ll n) {
  for(ll i=0;i<=n;i++) {
    if(i==0) {
      tfact[i]=1;
    }
    else {
      tfact[i]=tfact[i-1]*i%mod;
    }
  }
}

//nCk 繰り返し高速
ll comb(ll n, ll k) {
  return tfact.at(n)*mpow(tfact.at(k),mod-2)%mod*mpow(tfact.at(n-k),mod-2)%mod;
}

int main() {
  ll n,k;
  cin >> n >> k;
  fact(n);
  ll r=n-k;
  for(ll i=1;i<=k;i++) {
    if(i>r+1) {
      cout << 0 << endl;
      continue;
    }
    ll ans=comb(r+1,i);
    ans=ans*comb(k-i+(i-1),i-1)%mod;
    cout << ans << endl;
  }
}