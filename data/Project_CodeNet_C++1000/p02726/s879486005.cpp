#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, x, y;
  cin >> n >> x >> y;
  --x; --y;
  vector<int> ans(n);
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int cur = abs(i - j);
      cur = min(cur, abs(i - x) + 1 + abs(j - y));
      cur = min(cur, abs(i - y) + 1 + abs(j - x));
      ans[cur] += 1;
    }
  }
  for (int i = 1; i < n; i++) {
    cout << ans[i] << '\n';
  }
  return 0;
}
