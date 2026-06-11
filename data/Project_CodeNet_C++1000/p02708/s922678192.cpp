#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
const ll mod = 1e9 +7;
ll MAX_n = 2e5+1;
ll modpow(ll a, ll b){
  ll res = 1;
  while(b>0){
    if(b&1){
      res =res * a;
      res =res % mod;
    }
    a =a *a%mod;
    b >>=1;
  }
  return res;
}
ll modinv(ll a){
  return modpow(a, mod-2);
}
vector<ll> iv(MAX_n);
void init(ll n){
  for(ll i=1; i<=n; i++){
    iv.at(i) = modinv(i);
  }
  return;
}
ll modc(ll n, ll k){
  if(k>n-k) k = n-k;
  ll res = 1;
  for(ll i=n; i>=n-k+1;i--){
    res = res * i %mod;
  }
  for(ll i =2; i<=k; i++){
    res =res * modinv(i) %mod;
  }
  return res;
}

int main(){
  ll n,k;
  cin>>n>>k;
  ll ans =0;
  for(ll i =k; i<=n+1; i++){
    ans += ((2*n+3-i)*i/2- i*(i+1)/2 +1)%mod;
    ans%=mod;
  }
  ans %=mod;
  cout<<ans<<endl;
  //    cout << fixed << setprecision(10);
}
