#include <bits/stdc++.h>
using namespace std;

#define int long long
using ll = long long;
using ull = unsigned long long;
#define repi(n) for (long long i = 0; i < (n); ++i)
#define repj(n) for (long long j = 0; j < (n); ++j)
#define repk(n) for (long long k = 0; k < (n); ++k)
#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define itr(itr) for (auto&& v : (itr))
#define updatemax(t, v) (t = std::max(t, (v)))
#define updatemin(t, v) (t = std::min(t, (v)))

signed main() {
  ll x, k, d;
  cin >> x >> k >> d;
  x = abs(x);
  ll c = min(x / d, k);
  x -= c * d;
  k -= c;
  if (k > 0 && abs(x) > abs(x - d)) {
    x -= d;
    --k;
  }
  cout << (k % 2 ? min(abs(x + d), abs(x - d)) : abs(x)) << endl;
}
