#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1000000007;

ll Ep(ll x, ll y){
  if(y == 1) return x;
  ll r = Ep(x,y/2);
  if(y%2 == 1) return r *r%MOD *x%MOD;
  else return r *r%MOD;
}
ll comb(ll m, ll n){
  if(m < n) return 0;
  ll ans = 1;
  for(int i=0; i<n; ++i){
    ans *= m-i;
    ans %= MOD;
    ans *= Ep(n-i, MOD-2);
    ans %= MOD;
  }
  return ans;
}

int main(){
  int n, a, b;
  cin >> n >> a >> b;
  ll ans = Ep(2,n)-1;
  a = comb(n,a);
  b = comb(n,b);
  ans -= a-MOD;
  ans %= MOD;
  ans -= b-MOD;
  ans %= MOD;
  cout << ans << endl;
}