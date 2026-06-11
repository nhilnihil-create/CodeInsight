#include <bits/stdc++.h>

#define rep(i, ss, ee) for (int i = ss; i < ee; ++i)
using namespace std;
int N, D, ans = 0;
double x, y;
inline bool d(double x, double y) { return (D >= hypot(x, y)); }
void solve() {
  cin >> N >> D;
  rep(i, 0, N) {
    cin >> x >> y;
    if (d(x, y)) ans++;
  }
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
}