#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> s(h+1);
  rep(i, h) cin >> s[i];
  rep(i, h) s[i] += '#';
  s[h] = "";
  rep(j, w+1) s[h] += '#';

  vector<vector<int>> num_lighted(h, vector<int>(w, -1));
  rep(i, h) {
    int sj = -1;
    rep(j, w+1) {
      if (sj == -1) {
        if (s[i][j] == '.') sj = j;
      } else {
        if (s[i][j] == '#') {
          for (int k = sj; k < j; ++k) num_lighted[i][k] += j - sj;
          sj = -1;
        }
      }
    }
  }
  rep(j, w) {
    int si = -1;
    rep(i, h+1) {
      if (si == -1) {
        if (s[i][j] == '.') si = i;
      } else {
        if (s[i][j] == '#') {
          for (int k = si; k < i; ++k) num_lighted[k][j] += i - si;
          si = -1;
        }
      }
    }
  }
  int ans = 0;
  rep(i, h) rep(j, w) ans = max(ans, num_lighted[i][j]);
  cout << ans << endl;
  // rep(i, h) {
  //   rep(j, w) printf("%2d ", num_lighted[i][j]);
  //   printf("\n");
  // }
  return 0;
}