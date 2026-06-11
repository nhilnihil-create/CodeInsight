#include <bits/stdc++.h>
using namespace std;

// using ll = long long;
using ull = unsigned long long;
#define repi(n) for (long long i = 0; i < (n); ++i)
#define repj(n) for (long long j = 0; j < (n); ++j)
#define repk(n) for (long long k = 0; k < (n); ++k)
#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define itr(itr) for (auto&& v : (itr))
#define updatemax(t, v) (t = std::max(t, (v)))
#define updatemin(t, v) (t = std::min(t, (v)))

#include <boost/multiprecision/cpp_int.hpp>
using ll = boost::multiprecision::cpp_int;

ll d[5000], dsum[5001];
int main() {
  ll k, querylen;
  cin >> k >> querylen;
  repi(k) cin >> d[i];
  repi(querylen) {
    ll n, x, m;
    cin >> n >> x >> m;
    --n;
    x %= m;
    dsum[0] = 0;
    ll plusforoneloop = 0;
    repj(k) {
      if (d[j] % m) ++plusforoneloop;
      dsum[j + 1] = dsum[j] + d[j] % m;
    }
    ll loopnum = n / k, rest = n % k, xb = loopnum * dsum[(int)k] + x;
    ll res = loopnum * plusforoneloop - xb / m;
    xb %= m;
    // cout << "xb:" << xb << " rest:" << rest << endl;
    repj(rest) {
      ll newxb = (xb + d[j]) % m;
      if (newxb > xb) ++res;
      xb = newxb;
    }
    cout << res << endl;
  }
}
