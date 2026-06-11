#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
signed main() { 
  ios::sync_with_stdio(false); cin.tie(0);
  int n, m;
  cin >> n >> m;
  int k = (n - 1) / 2;
  vector<pair<int, int>> ans;
  for (int i = (k + 1) / 2 * 2 - 1, j = 1; i >= 1; i -= 2, j++) {
    ans.emplace_back(j, j + i);
  }
  for (int i = k / 2 * 2, j = n; i >= 2; i -= 2, j--) {
    ans.emplace_back(j, j - i);
  }
  for (int i = 0; i < m; i++) {
    cout << ans[i].first << " " << ans[i].second << '\n';
  }
  return 0;
}