#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  for (int i = 0; i < h; i++) {
    cin >> s[i];
  }
  vector<vector<int>> f(h, vector<int>(w));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (i + j == 0) {
        f[0][0] = (s[0][0] == '#');
      } else {
        f[i][j] = (int) 1e9;
        if (i > 0) f[i][j] = min(f[i][j], f[i - 1][j] + (s[i - 1][j] == '.' && s[i][j] == '#'));
        if (j > 0) f[i][j] = min(f[i][j], f[i][j - 1] + (s[i][j - 1] == '.' && s[i][j] == '#'));
      }
    }
  }
  cout << f[h - 1][w - 1] << endl;
  return 0;
}