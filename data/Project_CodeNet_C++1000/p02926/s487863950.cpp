#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../lib/dump.hpp"
#else
#define dump(...)
#define dumpv(...)
#endif

#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef long long ll;
typedef pair<int, int> P;
typedef pair<double, double> Pd;
typedef pair<double, int> Pi;
const int MOD = 1e9 + 7;
const int INF = 1001001001;
const ll LINF = 1001002003004005006ll;

void solve()
{
  int N;
  cin >> N;
  vector<P> p;
  rep(i, N) {
    int x, y;
    cin >> x >> y;
    if (x || y) p.push_back(P(x, y)); // 0は弾く
  }
  function<double(P)> dist = [&](P a) {
    return sqrt((double)a.first * a.first + (double)a.second * a.second);
  };
  function<Pd(P)> norm = [&](P a) {
    Pd b;
    double l = dist(a);
    b.first = (double)a.first / l;
    b.second = (double)a.second / l;
    return b;
  };
  function<double(Pd, Pd)> dot = [&](Pd a, Pd b) {
    return a.first * b.first + a.second * b.second;
  };
  function<double(Pd, Pd)> cross = [&](Pd a, Pd b) {
    return a.first * b.second - a.second * b.first;
  };
  function<double(P)> deg = [&](P a) {
    return atan2((double)a.second, (double)a.first) * 180 / M_PI;
  };
  dump(p);
  // 角度を計算
  vector<Pi> d;
  rep(i, p.size()) d.push_back(Pi(deg(p[i]), i));
  sort(d.begin(), d.end());
  dump(d);
  double ans = 0.0;
  rep(l, p.size()) {
    int r = l;
    P a = { 0, 0 };
    rep(i, p.size()) {
      a.first += p[d[r].second].first;
      a.second += p[d[r].second].second;
      ans = max(ans, dist(a));
      r = (r + 1) % p.size();
    }
  }
  cout << ans << endl;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  // freopen("temp.1", "r", stdin);
  solve();
  return 0;
}