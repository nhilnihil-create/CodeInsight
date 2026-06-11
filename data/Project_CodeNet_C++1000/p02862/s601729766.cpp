#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using vvi = vector<vector<int>>;
using pii = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define pb push_back

const int MOD=1e9+7;
const int MAX=1e6+5;
vll modfac(MAX,1);

ll modpow(ll m,ll n,ll p) {
  if(n==0) return 1;
  ll res=modpow(m,n/2,p);
  if(n%2==0) res=(res*res)%p;
  else res=(((res*res)%p)*m)%p;
  return res;
}

ll modinv(ll m,ll p) {
  return modpow(m,p-2,p);
}

ll modcom(ll n,ll r,ll p) {
  return ((modfac[n]*modinv(modfac[r],p))%p*modinv(modfac[n-r],p))%p;
}

int main() {
  ll x,y; cin>>x>>y;
  ll ans=0;

  for(ll i=1;i<=MAX;i++) {
    modfac[i]=modfac[i-1]*i%MOD;
  }

  for(ll i=0;i<=min(x/2,y);i++) {
    if(y-i==2*(x-2*i)) {
      ans+=modcom(i+(y-i)/2,i,MOD);
      ans%=MOD;
    }
  }
  cout<<ans<<endl;
}
