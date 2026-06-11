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
  rep(i, n) rep(j, i) {
    int temp = 0;
    rep(k, d) {
      int y = x[i][k] - x[j][k];
      temp += y * y;
    }
    int r = sqrt(temp) + 0.5;
    if (r*r == temp) ans++;
  }
  cout << ans << '\n';
  return 0;
}