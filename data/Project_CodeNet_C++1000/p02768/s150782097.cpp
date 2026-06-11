#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<(ll)n;++i)
using P = pair<ll,ll>;

const ll MOD = 1000000007;

// nのcnt乗を計算
ll pow2( ll n, ll cnt ){
  if( cnt == 1 ) return n;
  if( cnt == 0 ) return 1;
  if( cnt%2 == 0 ){
    ll tmp = pow2(n,cnt/2);
    return tmp%MOD*tmp%MOD;
  }else{
    ll tmp = pow2(n,cnt/2);
    return tmp%MOD*n%MOD*tmp%MOD;
  }
}

// n*(n-1)*...*(n-cnt+1) を計算
ll fac( ll n, ll cnt ){
  if( cnt == 1 ) return n;
  if( cnt == 0 ) return 1;
  return fac(n-1,cnt-1)%MOD*n%MOD;
}

int main(){
  ll n,a,b;cin >> n >> a >> b;

  // nCa mod MOD を計算
  ll xa = fac(n,a);
  ll ya = fac(a,a);
  ll amod = xa*pow2(ya,MOD-2)%MOD;
  if( amod < 0 ) amod += MOD;
  // cout << xa << " " << ya << " " << amod << endl;

  // nCb mod MOD を計算
  ll xb = fac(n,b);
  ll yb = fac(b,b);
  ll bmod = xb*pow2(yb,MOD-2)%MOD;
  if( bmod < 0 ) bmod += MOD;
  // cout << xb << " " << yb << " " << bmod << endl;

  ll ans = pow2(2,n);
  if( ans < 0 ) ans += MOD;
  ans -= amod + bmod + 1;

  while( ans < 0 )
    ans += MOD;

  cout << ans << endl;

  return 0;
}
