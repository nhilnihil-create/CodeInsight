#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<(ll)n;++i)
using P = pair<ll,ll>;

const ll MOD = 1000000007;

// nのcnt乗
ll pow2( ll n, ll cnt ){
  if( cnt == 0 ) return 1;
  if( cnt == 1 ) return n;
  ll tmp = pow2(n,cnt/2);
  if( cnt%2 == 0 )
    return tmp%MOD*tmp%MOD;
  else
    return tmp%MOD*n%MOD*tmp%MOD;
}

// nから(n-cnt+1)までの積 
ll fac( ll n, ll cnt ){
  if( cnt == 0 ) return 1;
  if( cnt == 1 ) return n ;
  return fac(n-1,cnt-1)%MOD*n%MOD;
}

int main(){
  ll x,y;cin >> x >> y;

  if( (2*x-y) < 0 || (2*x - y)%3 != 0 ){
    cout << 0 << endl;
    return 0;
  }
  ll t = (2*x-y)/3;
  ll s = x - 2*t;

  ll n = s+t;

  // nCs mod MOD を求める
  ll m = min(s,t);
  if( m < 0 ){
    cout << 0 << endl;
    return 0;
  }
  ll denominator = fac(m,m)%MOD;


  ll ans = fac(n,m) * pow2(denominator,MOD-2);
  ans %= MOD;

  cout << ans << endl;
  return 0;
}
