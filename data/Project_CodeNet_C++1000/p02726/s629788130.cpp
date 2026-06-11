#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, x, y;
  cin >> n >> x >> y;
  x--, y--;
  vector<int> ans(n, 0);
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int d = min(j - i, abs(x - i) + 1 + abs(y - j));
      ans[d]++;
    }
  }
  for (int i = 1; i < n; i++) {
    cout << ans[i] << '\n';
  }
  return 0;
}
