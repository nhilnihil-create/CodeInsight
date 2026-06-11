#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (long long i = 0; i < (n); ++i)
#define repr(i, a, b) for (auto i = (a); i < (b); ++i)
#define itr(x) for (auto&& v : (x))
#define updatemax(t, v) ((t) = std::max((t), (v)))
#define updatemin(t, v) ((t) = std::min((t), (v)))

int main() {
  ll n;
  cin >> n;
  vector<ll> p(n), q(n), t(n);
  rep(i, n) cin >> p[i];
  rep(i, n) cin >> q[i];
  rep(i, n) t[i] = i + 1;
  ll i = 0, pi, qi;
  do {
    if (t == p) pi = i;
    if (t == q) qi = i;
    ++i;
  } while (next_permutation(t.begin(), t.end()));
  cout << abs(pi - qi) << endl;
}
