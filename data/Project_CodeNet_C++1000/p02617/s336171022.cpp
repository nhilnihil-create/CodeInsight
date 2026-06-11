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

  ll n;
  cin >> n;
#if 0
  vvll g(n);
  rep(i, n - 1) {
    ll u, v;
    cin >> u >> v;
    u--;
    v--;
    if (u > v) {
      swap(u, v);
    }
    g[u].push_back(v);
    // g[v].push_back(u);
  }
#else
  vll u(n - 1), v(n - 1);
  rep(i, n - 1) {
    cin >> u[i] >> v[i];
    if (u[i] > v[i]) {
      swap(u[i], v[i]);
    }
  }
#endif
  vll s(n + 1);
  REP(i, n + 1) {
    s[i] = s[i] + i;
  }

  REP(i, n + 1) {
    s[i] += s[i - 1];
  }

  ll ans = 0;
  rep(i, n + 1) {
    ans += s[i];
  }

  rep(i, n - 1) {
    ll cnt = u[i] * (n - v[i] + 1);
    ans -= cnt;
  }

  cout << ans << endl;

  return 0;
}
