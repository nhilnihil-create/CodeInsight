#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;

  int c[10][10];
  rep(i, 10) rep(j, 10) c[i][j] = 0;

  for (int i = 1; i <= n; ++i) {
    string s = to_string(i);
    int x = s[0] - '0', y = s[s.size() - 1] - '0';
    ++c[x][y];
  }

  int ans = 0;
  rep(i, 10) rep(j, 10) ans += c[i][j] * c[j][i];

  cout << ans << endl;
  return 0;
}
