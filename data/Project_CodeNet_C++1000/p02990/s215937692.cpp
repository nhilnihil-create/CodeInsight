#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=LONG_LONG_MAX;

ll factmod(ll a,ll b,ll m) {
  if(a<b)return 0;
  ll s=1;
  while(a>=b){
    s = s*a % m;
    a -= 1;
  }
  return s;
}

ll modinv(ll a, ll m) {
  ll b = m, u = 1, v = 0;
  while (b) {
    ll t = a / b;
    a -= t * b; swap(a, b);
    u -= t * v; swap(u, v);
  }
  u %= m;
  if (u < 0) u += m;
  return u;
}

ll combmod(ll a,ll b,ll m){
  if(b==0)return 1;
  ll c=factmod(a,a-b+1,m);
  ll d=modinv(factmod(b,1,m),m);
  ll e=(c*d)%m;
  return e;
}

int main(){

  ll n,k;
  cin >> n >> k;

  for(int i=1;i<=k;i++){
    ll a;
    a=combmod(n-k+1,i,mod);
    a=(a*combmod(k-1,i-1,mod))%mod;
    cout << a << endl;
  }
  


}