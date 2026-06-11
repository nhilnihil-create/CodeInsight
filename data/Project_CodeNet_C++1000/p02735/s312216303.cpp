#include <bits/stdc++.h>

using namespace std;

template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  for (int i = 0; i < h; i++) {
    cin >> s[i];
  }
  vector<vector<int>> cnt(h, vector<int>(w));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (i == 0 && j == 0) {
        if (s[0][0] == '#') cnt[0][0] = 1;
      } else if (i == 0) {
        cnt[i][j] = cnt[i][j - 1] + (s[i][j - 1] == '.' && s[i][j] == '#');
      } else if (j == 0) {
        cnt[i][j] = cnt[i - 1][j] + (s[i - 1][j] == '.' && s[i][j] == '#');
      } else {
        cnt[i][j] = cnt[i][j - 1] + (s[i][j - 1] == '.' && s[i][j] == '#');
        chmin(cnt[i][j],
              cnt[i - 1][j] + (s[i - 1][j] == '.' && s[i][j] == '#'));
      }
    }
  }
  cout << cnt[h - 1][w - 1] << '\n';
  return 0;
}