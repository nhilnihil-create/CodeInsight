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

  ll h, w;
  cin >> h >> w;

  vs s(h);
  rep(i, h) {
    cin >> s[i];
  }
  vvll dp(h, vll(w, INF));
  dp[0][0] = 0;
  if (s[0][0] == '#') {
    dp[0][0] = 1;
  }
  rep(y, h) {
    rep(x, w) {
      ll cnt = 0;
      FOR(i, x, w - 1) {
        // 右に進む
        if (s[y][i] == '.' && s[y][i + 1] == '#') {
          cnt++;
        }
        chmin(dp[y][i + 1], dp[y][x] + cnt);
      }

      cnt = 0;
      FOR(i, y, h - 1) {
        // 下に進む
        if (s[i][x] == '.' && s[i + 1][x] == '#') {
          cnt++;
        }
        chmin(dp[i + 1][x], dp[y][x] + cnt);
      }
    }
  }

  cout << dp[h - 1][w - 1] << endl;

  return 0;
}
