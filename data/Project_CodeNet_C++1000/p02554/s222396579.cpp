#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9+7;

ll powmod(ll x, ll n){
  ll ret = 1;

  for (ll i=0; i<n; i++){
    ret = ret * x % MOD;
  }

  return ret;
}

int main(void){
  ll n, ans;
  cin >> n;

  ans = powmod(10,n);
  ans -= powmod(9,n);
  ans -= powmod(9,n);
  ans += powmod(8,n);
  ans %= MOD;
  ans = (ans+MOD)%MOD;

  cout << ans;
}