#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;

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
const long long INF = 1LL << 60;

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(20);

  ll n, t;
  cin >> n >> t;

  vll a(n + 1), b(n + 1);
  REP(i, n + 1) {
    cin >> a[i] >> b[i];
  }

  vvll ldp(n + 2, vll(t + 1)), rdp(n + 2, vll(t + 1));
  REP(i, n + 1) {
    rep(j, t) {
      chmax(ldp[i][j], ldp[i - 1][j]);
      if (j > 0) {
        chmax(ldp[i][j], ldp[i][j - 1]);
      }
      if (j + a[i] < t) {
        chmax(ldp[i][j + a[i]], ldp[i - 1][j] + b[i]);
      }
    }
  }

  for (int i = n; i > 0; i--) {
    rep(j, t) {
      chmax(rdp[i][j], rdp[i + 1][j]);
      if (j > 0) {
        chmax(rdp[i][j], rdp[i][j - 1]);
      }
      if (j + a[i] < t) {
        chmax(rdp[i][j + a[i]], rdp[i + 1][j] + b[i]);
      }
    }
  }

  ll ans = 0;
  REP(i, n + 1) {
    rep(j, t) {
      ll v = ldp[i - 1][j] + rdp[i + 1][t - 1 - j];
      chmax(ans, v + b[i]);
    }
  }

  cout << ans << endl;

  return 0;
}
