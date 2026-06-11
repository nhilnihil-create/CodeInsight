#include <bits/stdc++.h>
using namespace std;

// boost
#include <boost/multiprecision/cpp_int.hpp>
using boost::multiprecision::cpp_int;

using ll = long long;
using ld = long double;

using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;
using vld = vector<ld>;
using vvld = vector<vld>;

typedef pair<ll, ll> P;

#define bit(n) (1LL << (n))

//#define int long long

#define all(v) v.begin(), v.end()

#define rep(i, n) for (ll i = 0; i < n; i++)
#define REP(i, n) for (ll i = 1; i < n; i++)

#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define FORm(i, m) for (auto i = m.begin(); i != m.end(); i++)

template <class T>
inline void chmax(T& a, T b) {
  a = std::max(a, b);
}
template <class T>
inline void chmin(T& a, T b) {
  a = std::min(a, b);
}

#define mod (ll)(1e9 + 7)
// #define mod (998244353ll)

const long long INF = 1LL << 60;

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(20);

  ll x, y, a, b, c;
  cin >> x >> y >> a >> b >> c;

  vll p(a), q(b), r(c);
  rep(i, a) cin >> p[i];
  rep(i, b) cin >> q[i];
  rep(i, c) cin >> r[i];

  sort(all(p));
  sort(all(q));
  reverse(all(p));
  reverse(all(q));

  priority_queue<ll> qp, qq, qr;
  rep(i, min(a, x)) qp.push(p[i]);
  rep(i, min(b, y)) qq.push(q[i]);
  rep(i, c) qr.push(r[i]);
  qp.push(0);
  qq.push(0);
  qr.push(0);

  ll ans = 0;

  rep(i, x + y) {
    ll mx = 0;
    chmax(mx, qp.top());
    chmax(mx, qq.top());
    chmax(mx, qr.top());

    ans += mx;

    if (mx == qp.top())
      qp.pop();
    else if (mx == qq.top())
      qq.pop();
    else
      qr.pop();
  }

  cout << ans << endl;

  return 0;
}
