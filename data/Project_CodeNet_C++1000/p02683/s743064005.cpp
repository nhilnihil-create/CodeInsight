#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
int main() {
  int n, m, x;
  cin >> n >> m >> x;
  vector<vector<int>> a(n, vector<int>(m+1));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= m; j++) {
      cin >> a[i][j];
    }
  }

  int min = 10000000;
  for (int is = 0; is < 1<<n; is++) {
    vector<int> b(m+1);
    for (int i = 0; i < n; i++) {
      if (is>>i&1) {
        for (int j = 0; j <= m; j++) b[j] += a[i][j];
      }
    }
    bool t = true;
    for (int k = 1; k <= m; k++) {
      if (b[k] < x) t = false;
    }
    if (t && b[0] < min) min = b[0];
  }

  if (min == 10000000) cout << -1 << endl;
  else cout << min << endl;

  return 0;
}