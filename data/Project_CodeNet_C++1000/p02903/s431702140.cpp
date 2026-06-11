#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll h, w, a, b;
  cin >> h >> w >> a >> b;

  vector<vector<int>> s(h, vector<int>(w, 0));

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (i < b && a <= j) s[i][j] = 1;
      if (b <= i && j < a) s[i][j] = 1;
    }
  }

  rep(i, h) {
    rep(j, w) cout << s[i][j];
    cout << endl;
  }

  return 0;
}
