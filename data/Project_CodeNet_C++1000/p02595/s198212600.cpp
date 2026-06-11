#include <bits/stdc++.h>
#define rep(i, ss, ee) for (int i = ss; i < ee; ++i)
using namespace std;
void solve() {
  long long N, D, x, y, ans = 0;
  cin >> N >> D;
  D *= D;
  rep(i, 0, N) {
    cin >> x >> y;
    ans += (D >= x * x + y * y);
  }
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
}