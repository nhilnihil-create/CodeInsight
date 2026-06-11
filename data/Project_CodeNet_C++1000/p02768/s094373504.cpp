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
    return tmp*tmp%MOD;
  else
    return tmp*n%MOD*tmp%MOD;
}

// nから(n-cnt+1)までの積
ll factorial( ll n, ll cnt ){
  if( cnt == 0 ) return 1;
  return n%MOD*factorial(n-1,cnt-1)%MOD;
}


int main(){
  ll n,a,b;cin >> n >> a >> b;
  ll ans = pow2(2,n) - 1;

  // nCa mod MOD
  ll a_denominator = factorial(a,a);
  ll nca = factorial(n,a)%MOD * pow2(a_denominator,MOD-2);
  nca %= MOD;

  // nCb mod MOD
  ll b_denominator = factorial(b,b);
  ll ncb = factorial(n,b)%MOD * pow2(b_denominator,MOD-2);
  ncb %= MOD;

  ans -= nca + ncb;

  while( ans < 0 )
    ans += MOD;

  cout << ans << endl;

  return 0;
}
