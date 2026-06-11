#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, m, x, res = 1145141919;

  cin >> n >> m >> x;

  vector<int> c(n);
  vector<vector<int>> a(n, vector<int>(m));

  for (int i = 0; i < n; ++i) {
    cin >> c[i];
    for (int j = 0; j < m; ++j) cin >> a[i][j];
  }

  for (int bit = 0; bit < (1 << n); ++bit) {
    int cost = 0;
    vector<int> deg(m, 0);
    for (int i = 0; i < n; ++i) {
      if (bit & (1 << i)) {
        cost += c[i];
        for (int j = 0; j < m; ++j) deg[j] += a[i][j];
      }
    }
    if (all_of(deg.begin(), deg.end(), [&](int d) { return d >= x; })) {
      res = min(res, cost);
    }
  }
  cout << (res == 1145141919 ? -1 : res) << endl;
  return 0;
}
