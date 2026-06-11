#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, y;
  cin >> x >> y;
  vector<string> G(x);
  vector<vector<int>> flip(x,vector<int>(y));
  for (auto &s : G) cin >> s;
  if (G[0][0] == '.') flip[0][0] = 0;
  else flip[0][0] = 1;
  for (int i = 1; i < y; i++) {
    flip[0][i] = flip[0][i-1];
    if (G[0][i-1] == '.' && G[0][i] == '#') flip[0][i] += 1;
  }
  for (int i = 1; i < x; i++) {
    for (int j = 0; j < y; j++) {
      if (j == 0) {
        flip[i][0] = flip[i-1][0];
        if (G[i-1][0] == '.' && G[i][0] == '#') flip[i][0] += 1;
      }
      else {
        int u = flip[i-1][j];
        int l = flip[i][j-1];
        if (G[i][j] == '#') {
          if (G[i-1][j] == '.') u++;
          if (G[i][j-1] == '.') l++;
        } 
        flip[i][j] = min(u,l);
      }
    }
  }
  cout << flip[x-1][y-1] << endl;
}