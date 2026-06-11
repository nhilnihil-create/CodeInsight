#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int inf = 1000000000; 
const ll mod = 1e9+7;

ll powmod(ll x,ll y){
  if(y == 0){
    return 1;
  }
  if(y == 1){
    return x%mod;
  }
  if(y%2 == 0){
    return (powmod(x,y/2)*powmod(x,y/2))%mod;
  }
  else{
    return (x*((powmod(x,y/2)*powmod(x,y/2)%mod)))%mod;
  }
}

int main(){
  ll n,k;
  cin >> n >> k;
  ll d[k+1];
  for(ll i=k; i>0; i--){
    ll a = k/i;
    d[i] = powmod(a,n);
    for(ll j=2*i; j<=k; j+=i){
      d[i]-=d[j];
      if(d[i] <0){
        d[i]+=ll(1e9+7);
      }
    }
  }
  ll ans = 0;
  for(ll i=1; i<=k; i++){
    //cout << d[i] << endl;
    ans += d[i]*i;
    ans %= ll(1e9+7);
  }
  cout << ans << endl;
}