#include <algorithm>
#include <cassert>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
ll const INF = 1LL << 60;
ll const mod = 1e9 + 7;

ll recursive_square(ll x, ll n) {
  x %= mod;
  if (n == 0) return 1;
  if (n % 2 == 0) {
    ll t = recursive_square(x, n / 2);
    return t * t % mod;
  }
  return x * recursive_square(x, n - 1) % mod;
}

ll comb(ll n, ll k) {
  ll x = 1;
  for (ll i = n - k + 1; i <= n; i++) {
    x = x * i;
    x = x % mod;
  }
  ll y = 1;
  for (ll i = 1; i <= k; i++) {
    y = y * i;
    y = y % mod;
  }
  y = recursive_square(y, mod - 2);
  return x * y % mod;
}

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  ll all_comb = recursive_square(2, n);
  ll nCa = comb(n, a);
  ll nCb = comb(n, b);
  ll ans = (all_comb - 1 - nCa - nCb) % mod;
  if (ans < 0) ans += mod;
  cout << ans << endl;
  return 0;
}