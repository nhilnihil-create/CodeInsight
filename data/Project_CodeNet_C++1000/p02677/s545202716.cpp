#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);

struct R {
  double s, l, t, x, y;
  void p(double tt) {
    t = tt;
    x = l * cos(t);
    y = l * sin(t);
  }
  double ht(R m) { return (s * 60.0 + m.s) / 720.0 * 2.0 * PI; }
  double mt() { return s / 60.0 * 2.0 * PI; }
  double d(R r) { return hypot(x - r.x, y - r.y); }
};

void solve() {
  R h, m;
  cin >> h.l >> m.l >> h.s >> m.s;
  h.p(h.ht(m));
  m.p(m.mt());
  cout << h.d(m) << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(10);
  solve();
}