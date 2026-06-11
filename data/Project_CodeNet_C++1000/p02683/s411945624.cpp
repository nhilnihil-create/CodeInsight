#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;

int main() {
  int n, m, x;
  cin >> n >> m >> x;
  vector<int> c(n);
  vector<vector<int>> a(n, vector<int> (m, 0));
  for (int i = 0; i < n; ++i) {
    cin >> c[i];
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }

  int rtn = INF;
  for (int bit = 0; bit < (1 << n); ++bit) {
    int rtnCst = 0;
    vector<int> rikai(m, 0);
    for (int i = 0; i < n; ++i) {
      if ((bit >> i) & 1) {
        rtnCst += c[i];
        for (int j = 0; j < m; ++j) {
          rikai[j] += a[i][j];
        } 
      }
    }
    bool allok = true;
    for (int k = 0; k < m; ++k)
      if (rikai[k] < x) allok = false;
    if (allok) rtn = min(rtn, rtnCst);
  }
  if (rtn == INF) cout << "-1\n";
  else cout << rtn << endl;
}
