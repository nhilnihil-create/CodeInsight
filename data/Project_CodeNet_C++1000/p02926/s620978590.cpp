#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;
using P = pair<int, int>;
constexpr ld EPS = 1e-12;
constexpr int INF = numeric_limits<int>::max() / 2;
constexpr int MOD = 1e9 + 7;

template <typename T>
void printv(const vector<T> &v) {
  int sz = v.size();
  for (int i = 0; i < sz; i++) {
    cout << v[i] << " \n"[i == sz - 1];
  }
}

struct Point {
  ld x, y, rad;
};

bool operator<(const Point &lhs, const Point &rhs) { return lhs.rad < rhs.rad; }

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<ld> x(n), y(n);
  vector<ld> rad(n);
  vector<Point> ps;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
    complex<ld> c(x[i], y[i]);
    rad[i] = arg(c) / acos(-1.0) * 180;
    if (rad[i] < 0) rad[i] += 360;
    ps.push_back(Point{x[i], y[i], rad[i]});
  }
  sort(ps.begin(), ps.end());
  ld ret = 0;
  for (int i = 0; i < n; i++) {
    ld xsum = 0, ysum = 0;
    for (int j = 0; j < n; j++) {
      // ps[i] ~ ps[i+j]
      int index = (i + j) % n;
      xsum += ps[index].x;
      ysum += ps[index].y;
      ret = max(ret, sqrt(xsum * xsum + ysum * ysum));
    }
  }
  cout << fixed << setprecision(20) << ret << endl;
}
