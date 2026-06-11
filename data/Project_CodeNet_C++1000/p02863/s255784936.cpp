#include <bits/stdc++.h>
#include <type_traits>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i <= (n); ++i)
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
#define ddrep(i, n) for (int i = n; i > 0; --i)
#define srep(i, s, t) for (int i = s; i < t; ++i)
#define ssrep(i, s, t) for (int i = s; i <= t; ++i)

#define rng(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back
#define fi first
#define se second

#define chmax(x, y) (x = max(x, y))
#define chmin(x, y) (x = min(x, y))

using pi = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using ld = long double;

template <class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  os << "(" << p.first << "," << p.second << ")";
  return os;
}

template <class T> ostream &operator<<(ostream &os, const vector<T> &v) {
  os << "{";
  rep(i, (int)v.size()) {
    if (i)
      os << ",";
    os << v[i];
  }
  os << "}";
  return os;
}

template <typename T, size_t S> void printArray(const T (&array)[S]) {
  for (auto val : array)
    std::cout << val << ", ";
  std::cout << "\n";
}

const int mod = 1e9 + 7;
const int inf = 1e9 + 5;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << std::setprecision(10);

  int n, t; std::cin >> n >> t;
  vector<pi> ab(n);
  rep(i, n) {
    std::cin >> ab[i].fi >> ab[i].se;
  }
  vvi dp1(n, vi(t)), dp2(n, vi(t));
  rep(i, n) {
    drep(j, t) {
      if (i == 0) dp1[i][j] = (j-ab[i].fi >= 0 ? ab[i].se : 0);
      else if (j-ab[i].fi < 0) dp1[i][j] = dp1[i-1][j];
      else dp1[i][j] = max(dp1[i-1][j], dp1[i-1][j-ab[i].fi]+ab[i].se);
    }
  }
  drep(i, n) {
    drep(j, t) {
      if (i == n-1) dp2[i][j] = (j-ab[i].fi >= 0 ? ab[i].se : 0);
      else if (j-ab[i].fi < 0) dp2[i][j] = dp2[i+1][j];
      else dp2[i][j] = max(dp2[i+1][j], dp2[i+1][j-ab[i].fi]+ab[i].se);
    }
  }
  int ans = 0;
  rep(i, n) {
    if (i == 0) chmax(ans, dp2[i+1][t-1] + ab[i].se);
    else if (i == n-1) chmax(ans, dp1[n-2][t-1] + ab[i].se);
    else {
      rep(j, t) chmax(ans, dp1[i-1][j] + dp2[i+1][t-j-1] + ab[i].se);
    }
  }
  std::cout << ans << "\n";
}
