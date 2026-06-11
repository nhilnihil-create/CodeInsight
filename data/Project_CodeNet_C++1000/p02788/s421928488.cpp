#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < n; ++i)
#define sz(x) int(x.size())
#define ALL(c) (c).begin(), (c).end()
#define SUM(x) std::accumulate(ALL(x), 0LL)
#define MIN(v) *std::min_element(v.begin(), v.end())
#define MAX(v) *std::max_element(v.begin(), v.end())
#define EXIST(v, x) (std::find(v.begin(), v.end(), x) != v.end())
#define FORV(i, v) for (auto i = v.begin(); i != v.end(); i++)
using namespace std;

using ll = long long;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
const int INF = 1001001001;
const long long INFL = LLONG_MAX / 3;
const double eps = (1e-9);

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n, d, a;
  cin >> n >> d >> a;
  vector<vector<ll>> x(n, vector<ll>(2, 0));
  rep(i, n) cin >> x[i][0] >> x[i][1];

  sort(ALL(x));

  deque<pair<ll, ll>> imo;
  ll ans = 0;
  ll cur = 0;  // 現在位置が何回爆破されたか

  rep(i, n) {
    while (!imo.empty() && imo.front().first <= x[i][0]) {
      cur += imo.front().second;
      imo.pop_front();
    }

    x[i][1] -= cur * a;
    if (x[i][1] > 0) {
      ll num = max(ll(0), (x[i][1] + a - 1) / a);  // i 番目のモンスターを仕留めるのに必要な bomb
      cur += num;
      imo.push_back(make_pair(ll(x[i][0] + 2 * d + 1), -num));
      ans += num;
    }
  }

  cout << ans << endl;

  return 0;
}
