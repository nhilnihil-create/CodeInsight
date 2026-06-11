#include <bits/stdc++.h>
#define rep(i, n)     for (int i = 0; i < (int)(n); ++i)
#define rep1(i, n)    for (int i = 1; i <= (int)(n); ++i)
#define irep(i, a, n) for (int i = a; i < (int)(n); ++i)
#define rrep(i, n)    for (int i = (int)(n) - 1; i >= 0; --i)
#define rrep1(i, n)   for (int i = (int)(n); i >= 1; --i)
#define allrep(V, v)  for (auto &&V : v)
#define all(x)        (x).begin(), (x).end()
using lint = long long;
constexpr int    INF  = 1 << 30;
constexpr lint   INFL = 1LL << 62;
constexpr int    MOD  = 1e9 + 7;
constexpr double EPS  = 1e-9;
using namespace std;

struct vector_2d {
  double x, y;
  vector_2d(void) : x(0), y(0) {}
  vector_2d(double x_value, double y_value) : x(x_value), y(y_value) {}
  const int  orthant(void) const { return (y >= 0) ? (x >= 0 ? 1 : 2) : (x >= 0 ? 4 : 3); }
  const bool operator<(const vector_2d &v) const {
    int a = orthant(), b = v.orthant();
    if (a != b) return a < b;
    return x * v.y - y * v.x > 0;
  }
};

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);

  int n;
  cin >> n;
  vector<vector_2d> vec(n);
  rep (i, n) cin >> vec[i].x >> vec[i].y;
  sort(all(vec));
  double maxi = 0;
  rep (i, n) {
    int ni = i;
    vector_2d now;
    rep (j, n) {
      now.x += vec[(ni + j) % n].x;
      now.y += vec[(ni + j) % n].y;
      maxi   = max(maxi, now.x * now.x + now.y * now.y);
    }
  }
  double ans = sqrt(maxi);
  cout << ans << endl;
  return 0;
}