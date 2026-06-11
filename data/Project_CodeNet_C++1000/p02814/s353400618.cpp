#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (long long i = 0; i < (n); ++i)
#define repr(i, a, b) for (auto i = (a); i < (b); ++i)
#define itr(x) for (auto&& v : (x))
#define updatemax(t, v) ((t) = std::max((t), (v)))
#define updatemin(t, v) ((t) = std::min((t), (v)))

ll a[100100];
int main() {
  ll n, m;
  cin >> n >> m;
  rep(i, n) cin >> a[i];
  rep(i, n) a[i] /= 2;
  ll alcm = 1;
  rep(i, n) {
    alcm = lcm(alcm, a[i]);
    if (alcm > m) {
      cout << 0 << endl;
      return 0;
    }
  }
  rep(i, n) {
    if ((alcm / a[i]) % 2 == 0) {
      cout << 0 << endl;
      return 0;
    }
  }
  cout << m / alcm - m / (2 * alcm) << endl;
}
