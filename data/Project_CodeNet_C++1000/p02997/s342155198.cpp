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

  ll n, k;
  cin >> n >> k;

  ll mx = (n - 1) * (n - 2) / 2;

  if (k > mx) {
    cout << -1 << endl;
  } else {
    vector<P> edges;
    for (ll i = 2; i <= n; i++) {
      edges.emplace_back(1, i);
    }

    FOR(i, 2, n + 1) {
      FOR(j, i + 1, n + 1) {
        if (mx <= k) {
          goto end;
        }
        edges.emplace_back(i, j);
        mx--;
      }
    end:;
    }

    cout << edges.size() << endl;
    for (const auto& e : edges) {
      cout << e.first << " " << e.second << endl;
    }
  }

  return 0;
}
