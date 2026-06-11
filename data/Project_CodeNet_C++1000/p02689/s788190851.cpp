#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> h(n);
  for (int i = 0; i < n; i++) cin >> h[i];
  vector<vector<int>> path(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    path[a].push_back(b);
    path[b].push_back(a);
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    bool flag = true;
    for (int j = 0; j < path[i].size(); j++) {
      if (h[path[i][j]] >= h[i]) flag = false;
    }
    ans += flag;
  }
  cout << ans << endl;
  return 0;
}