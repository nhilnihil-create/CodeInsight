#include <iostream>

using namespace std;

void solve() {
  int N;
  cin >> N;

  int prev = 0;
  int ans = 0;
  int steps = 0;
  while (N--) {
    int h; cin >> h;
    if (prev >= h) {
      ans = max(ans, ++steps);
    } else {
      steps = 0;
    }

    prev = h;
  }

  cout << ans << endl;
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
