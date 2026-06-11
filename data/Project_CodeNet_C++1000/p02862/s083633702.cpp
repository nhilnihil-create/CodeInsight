#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using vll = vector<ll> ;
#define all(v) v.begin(),v.end()
const ll mod = 1e9+7;
 
ll modpow(ll a,ll b){
  ll ans=1%mod;
  while(b){	
    if(b&1) ans=(ans*a)%mod;
    a=(a*a)%mod;
    b=b>>1; 
  }
  return ans;
  }
 
ll modinv(ll a, ll m) {
  ll b=m,u=1,v=0;
  while(b){
    ll t = a/b;
    a -= t*b;
    swap(a,b);
    u -= t*v;
    swap(u,v);
  }
  u %= m;
  if(u<0) u += m;
  return u;
}
 
ll fact(ll k){
  ll tmp=k;
  if(k == 0) tmp=1;
  while(k>1){
    k--;
    tmp = tmp * k % mod;
  }
  return tmp;
}
 
int main(){
  ll X,Y;cin>>X>>Y;
  ll ans = 0;
  ll n=2*X-Y,m=2*Y-X;
  if(n>=0 && m>=0 && n%3==0 && m%3==0){
    n /= 3;
    m /= 3;
    ans += fact(n+m)*modinv(fact(n),mod)%mod*modinv(fact(m),mod)%mod;
    ans %= mod;
  }
  cout << ans << endl;
}