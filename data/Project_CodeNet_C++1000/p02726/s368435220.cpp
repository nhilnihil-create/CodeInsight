#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, x, y;
  cin >> n >> x >> y;
  x--;
  y--;
  vector<int> ans(n);
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int d = abs(i - j);
      d = min(abs(i - x) + 1 + abs(j - y), d);
      ans[d]++;
    }
  }
  for (int i = 1; i < n; i++) {
    cout << ans[i] << endl;
  }
}
