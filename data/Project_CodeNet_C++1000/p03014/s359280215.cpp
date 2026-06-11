#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int M = 1e7;
int si[] = {-1, 0, 1, 0};
int sj[] = {0, -1, 0, 1};

int main(){
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i,h) cin >> s[i];

  vector<vector<int>> l(h,vector<int>(w,0)), r(h,vector<int>(w,0));
  vector<vector<int>> t(h,vector<int>(w,0)), b(h,vector<int>(w,0));

  rep(i,h) {
    int c = 0;
    rep(j,w) {
      if (s[i][j] == '#') {
        l[i][j] = 0;
        c = 0;
      } else {
        l[i][j] = c;
        c++;
      }
    }
  }

  rep(i,h) {
    int c = 0;
    rep(j,w) {
      if (s[i][w-j-1] == '#') {
        r[i][w-j-1] = 0;
        c = 0;
      } else {
        r[i][w-j-1] = c;
        c++;
      }
    }
  }

  rep(j,w) {
    int c = 0;
    rep(i,h) {
      if (s[i][j] == '#') {
        t[i][j] = 0;
        c = 0;
      } else {
        t[i][j] = c;
        c++;
      }
    }
  }

  rep(j,w) {
    int c = 0;
    rep(i,h) {
      if (s[h-i-1][j] == '#') {
        b[h-i-1][j] = 0;
        c = 0;
      } else {
        b[h-i-1][j] = c;
        c++;
      }
    }
  }

  int ans = 0;
  rep(i,h) rep(j,w) {
    if (s[i][j] != '#') ans = max(ans, t[i][j]+b[i][j]+l[i][j]+r[i][j]+1);
  }
  cout << ans << endl;

  return 0;
}
