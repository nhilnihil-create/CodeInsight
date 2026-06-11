// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(ll __x = __start; __x < __end; __x++)

const ll MOD = 1000000007;

ll intpow(ll a, ll n) {
  if (n == 0) return 1;
  ll x = intpow(a, n/2);
  x = (x * x) % MOD;
  if (n&1) x = (x * a) % MOD;
  return x;
}

ll com(ll n, ll a) {
  ll x = 1, y = 1;
  loop(i,0,a) {
    x = (x * (n-i)) % MOD;
    y = (y * (i+1)) % MOD;
  }
  
  return (x * intpow(y, MOD-2)) % MOD;
}

int main() {
  ll n, a, b; cin >> n >> a >> b;
  ll ans = intpow(2, n);
  ans -= 1;
  ans -= com(n, a);
  if (ans < 0) ans += MOD;
  ans -= com(n, b);
  if (ans < 0) ans += MOD;
  cout << ans << endl;
  return 0;
}
