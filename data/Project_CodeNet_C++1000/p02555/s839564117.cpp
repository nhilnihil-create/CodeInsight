#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<(ll)n;++i)
using P = pair<ll,ll>;

const ll dv = 1000000007;

// n^s mod dv
ll pow2( ll n, ll s ){
  if( s == 0 ) return 1;
  if( s == 1 ) return n;
  ll tmp = pow2(n,s/2);
  if( s%2 == 0 ){
    return tmp%dv*tmp%dv;
  }else{
    return tmp%dv*tmp%dv*n%dv;
  }
}

// sから(s-t+1)までの積
ll fac( ll s, ll t ){
  if( t == 0 ) return 1;
  return (s-t+1)%dv*fac(s,t-1)%dv;
}

// nCr mod dv
ll comb( ll n, ll r ){
  ll num = fac(n,r);
  ll denom = fac(r,r);
  return num*pow2(denom,dv-2)%dv;
}

int main(){
  ll s;cin >> s;
  ll ans = 0;
  for(ll i=1;i<=s;++i){
    ll n = s - 3*i;
    if( n < 0 ) break;
    ans += comb(n+i-1,i-1)%dv;
    ans %= dv;
  }

  cout << ans << endl;


  return 0;
}
