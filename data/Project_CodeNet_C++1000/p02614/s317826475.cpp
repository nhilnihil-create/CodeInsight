/**
 * author:  virenkathiriya96
 * created: 2020.08.31 14:51:54 
**/

#include<bits/stdc++.h>

using namespace std;

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int h, w, k, ans = 0;
  cin >> h >> w >> k;
  vector<vector<int>> grid(h, vector<int>(w)), tmp(h, vector<int>(w));
  vector<int> H(h);
  vector<int> W(w);
  for (int i = 0; i < h; i++) H[i] = i;
  for (int j = 0; j < w; j++) W[j] = j;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      char c;
      cin >> c;
      if (c == '.') grid[i][j] = 0;
      else grid[i][j] = 1;
      tmp[i][j] = grid[i][j];
    }
  }
  int h2 = 1 << h;
  int w2 = 1 << w;
  for (int i = 0; i < h2; i++) {
    vector<int> dp1;
    for (int j = 0; j < h; j++) {
      if ((i & (1 << j)) != 0) {
        dp1.push_back(j);
      }
    }

    for (int ii = 0; ii < w2; ii++) {
      vector<int> dp2;
      for (int jj = 0; jj < w; jj++) {
        if ((ii & (1 << jj)) != 0) {
          dp2.push_back(jj);
        }
      }

      for (int iii = 0; iii < h; iii++) for (int jjj = 0; jjj < w; jjj++) tmp[iii][jjj] = grid[iii][jjj];
      for (int &x: dp1) {
        for (int jjjj = 0; jjjj < w; jjjj++) tmp[x][jjjj] = 2;
      }
      for (int &x: dp2) {
        for (int jjjj = 0; jjjj < h; jjjj++) tmp[jjjj][x] = 2;
      }

      int cnt = 0;
      for (int l = 0; l < h; l++) {
        for (int ll = 0; ll < w; ll++) {
          cnt += (tmp[l][ll] == 1);
        }
      }
      if (cnt == k) ans++;
    }
  }
  cout << ans << "\n";
  return 0;
}