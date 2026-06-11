#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9+7;
ll power(ll x, int p){
  ll res = 1;
  while(p--) res = res*x%mod;
  return res;
}
int main(){
  int n;
  cin >> n;
  ll ans = power(10, n)-power(9, n)-power(9, n)+power(8, n);
  ans %= mod;
  ans = (ans+mod)%mod;
  cout << ans << endl;
}