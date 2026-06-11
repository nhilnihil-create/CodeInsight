#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rng(a) a.begin(),a.end()
using namespace std;
using ll = long long;


int main() {
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i,h) cin >> s[i];
  int l[h][w];
  rep(i,h) {
    rep(j,w) {
      if(s[i][j]=='#') l[i][j] = 0;
      else if(j==0) l[i][0] = 1;
      else l[i][j] = l[i][j-1]+1;
    }
  }
  int r[h][w];
  rep(i,h) {
    for(int j = w-1; j >= 0; j--) {
      if(s[i][j]=='#') r[i][j] = 0;
      else if(j==w-1) r[i][j] = 1;
      else r[i][j] = r[i][j+1]+1;
    }
  }
  int u[h][w];
  rep(j,w) {
    rep(i,h) {
      if(s[i][j]=='#') u[i][j] = 0;
      else if(i==0) u[0][j] = 1;
      else u[i][j] = u[i-1][j]+1;
    }
  }
  int d[h][w];
  rep(j,w) {
    for(int i = h-1; i >= 0; i--) {
      if(s[i][j]=='#') d[i][j] = 0;
      else if(i==h-1) d[i][j] = 1;
      else d[i][j] = d[i+1][j] + 1;
    }
  }
  int ans = 0;
  rep(i,h) {
    rep(j,w) {
      if(s[i][j]=='#') continue;
      ans = max(ans,l[i][j]+r[i][j]+u[i][j]+d[i][j]-3);
    }
  }
  cout << ans << endl;
  return 0;
}