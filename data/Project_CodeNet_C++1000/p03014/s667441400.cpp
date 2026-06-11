#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int h,w;
string s[2000];

int u[2000][2000];
int d[2000][2000];
int l[2000][2000];
int r[2000][2000];

signed main() {
  cin >> h >> w;
  rep(i, h) cin >> s[i];

  int c;
  rep(i, h) {
    c=0;
    rep(j, w) {
      if(s[i][j] == '#') { c = -1; }
      l[i][j] = c++;
    }
  }
  rep(i, h) {
    c=0;
    for(int j=w-1; j>=0; j--) {
      if(s[i][j] == '#') { c = -1; }
      r[i][j] = c++;
    }
  }
  rep(j, w) {
    c=0;
    rep(i, h) {
      if(s[i][j] == '#') { c = -1; }
      u[i][j] = c++;
    }
  }
  rep(j, w) {
    c=0;
    for(int i=h-1; i>=0; i--) {
      if(s[i][j] == '#') { c = -1; }
      d[i][j] = c++;
    }
  }

  int ans = 0;
  rep(i, h) rep(j, w) {
    if(s[i][j] == '#') continue;
    ans = max(ans, u[i][j] + d[i][j] + l[i][j] + r[i][j] + 1);
  }
  cout << ans << endl;

}
