#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using P = pair<int,int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const ll mod = 1000000007;

ll powmod(ll x,ll n) {
  ll res = 1;
  rep(i,n) res = res * x % mod;
  return res;
}

int main() {
  ll n;
  cin >> n;
  ll U = powmod(10,n), A = powmod(9,n), B = powmod(8,n);
  if(U < 2 * A) U += mod;
  ll ans = U - 2 * A + B;
  ans %= mod;
  ans = (ans + mod) % mod;
  cout << ans << endl;
}