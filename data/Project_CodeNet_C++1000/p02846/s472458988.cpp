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

  ll t1, t2, a1, a2, b1, b2;
  cin >> t1 >> t2;
  cin >> a1 >> a2;
  cin >> b1 >> b2;

  ll g = (b1-a1)*t1, h = (b2-a2)*t2;

  if ((g > 0 && g + h > 0) || (g < 0 && g + h < 0)) {
    cout << 0 << endl;
    return 0;
  }

  if (g + h == 0) {
    cout << "infinity\n";
    return 0;
  }

  //cout << g << " " << h << endl;

  ll d = g - (2LL*g + h); //cout << d << endl;
  if (g % d == 0) cout << 2LL*(g/d+1LL)-2LL << endl;
  else cout << 2LL*(g/d+1LL)-1LL << endl;

  return 0;
}
