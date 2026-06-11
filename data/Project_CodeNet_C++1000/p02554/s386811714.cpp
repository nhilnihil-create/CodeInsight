#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
using ll = long long;
const int MOD = 1000000007;
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repp(i, m, n) for (int i = (int)(m); i < (int)(n); ++i)


ll myPow(ll x, ll n, ll m){
  if(n == 0)
    return 1;
  if(n % 2 == 0)
    return myPow(x * x % m, n / 2, m);
  else
    return x * myPow(x, n - 1, m) % m;
}

ll mmyPow(ll x, ll n, ll m){
  if (n == 0) return 1;
  ll y = 1;
  rep (i, n) {
    y = y * x % m;
  }

  return y;
}

int main() {
  ll n;  cin >> n;
  ll x, y, z;

  x = mmyPow (9, n, MOD);
  y = mmyPow (8, n, MOD);
  z = mmyPow (10, n, MOD);

  ll ans = (z - x - x + y) % MOD;
  ans = (ans + MOD) % MOD;
  cout << ans << endl;
}