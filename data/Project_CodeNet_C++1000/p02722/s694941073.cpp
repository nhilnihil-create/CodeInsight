#include <cstdio>
#include <climits>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>
#include <climits>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <utility>
#include <queue>
#include <cstring>
#include <set>
#include <map>
#include <complex>

#define rep(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
long long MOD = 1000000007;
long long INF = 1000000000000000; //10^15
typedef long long ll;
typedef unsigned long long ull;


ll powMod(ll x, ll n, ll mod) {
  if (n == 0) return 1;
  ll t = powMod(x, n/2, mod);
  t = t * t % mod;
  if (n & 1) return t * x % mod;
  return t;
}

ll gcd(ll a, ll b) {
  if (a == 0 || b == 0) return a + b;
  if (b > a) return gcd(b, a);
  return gcd(b, a % b);
}

int main(void) {

  ll n;
  cin >> n;

  if (n == 2) {
    cout << 1 << endl;
    return 0;
  }

  ll ans = 2;
  for (ll k = 2; k*k <= n; k++) {
    if ((n-1LL)%k == 0) {
      ans += 2LL;
      if (n-1LL == k*k) ans -= 1LL;
    }
  }

  ll m;
  for (ll k = 2; k*k <= n; k++) {
    if (n % k == 0) {
      m = n;
      while (m%k == 0) m /= k;
      if ((m-1)%k == 0) ans++;
    }
  }

  cout << ans << endl;

  return 0;

}
