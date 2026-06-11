#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n, d;
  cin >> n >> d;
  vector<vector<int>> x(n, vector<int>(d));
  rep(i, n) rep(j, d) cin >> x[i][j];

  vector<bool> is_square(1000000, false);
  rep(i, 1000) is_square[i*i] = true;

  int ans = 0;
  rep(i, n) for (int j = i+1; j < n; ++j) {
    int dist = 0;
    rep(k, d) dist += pow(x[i][k] - x[j][k], 2);
    if (is_square[dist]) ++ans;
  }
  cout << ans << endl;
  return 0;
}