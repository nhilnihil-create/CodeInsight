#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
#define rrep(i,n,g) for (int i = (n)-1; i >= (g); --i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int h,w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i,0,h) cin >> s[i];
  vector<vector<int>> yoko(h, vector<int>(w,0));
  rep(i,0,h) {
    rep(j,0,w) {
      if (j == 0) {
        if (s[i][j] == '.') yoko[i][j] = 1;
        continue;
      }
      if (s[i][j] == '.') yoko[i][j] = yoko[i][j-1] + 1;
    }
    rrep(j,w-1,0) {
      if (yoko[i][j] == 0 || yoko[i][j+1] == 0) continue;
      yoko[i][j] = yoko[i][j+1];
    }
  }
  vector<vector<int>> tate(h, vector<int>(w,0));
  rep(i,0,w) {
    rep(j,0,h) {
      if (j == 0) {
        if (s[j][i] == '.') tate[j][i] = 1;
        continue;
      }
      if (s[j][i] == '.') tate[j][i] = tate[j-1][i] + 1;
    }
    rrep(j,h-1,0) {
      if (tate[j][i] == 0 || tate[j+1][i] == 0) continue;
      tate[j][i] = tate[j+1][i]; 
    }
  }
  int ans = 0;
  rep(i,0,h) rep(j,0,w) {
    ans = max(ans, yoko[i][j] + tate[i][j] - 1);
  }
  cout << ans << endl;
  return 0;
}
