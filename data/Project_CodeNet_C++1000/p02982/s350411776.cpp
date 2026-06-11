#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, d;
  cin >> n >> d;
  vector<vector<int>> x(n, vector<int>(d));
  rep(i, n) rep(j, d) cin >> x[i][j];
  int ans = 0;
  for (int i=0; i<n-1; i++) {
    for (int j=i+1; j<n; j++) {
      int dis = 0;
      rep(k, d) {
        int s = x[i][k] - x[j][k];
        dis += s*s;
      }
      int s = sqrt(dis) + 0.5;
      if (s*s == dis) {
        ans++;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}