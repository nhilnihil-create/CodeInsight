#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for(int i = 0; i < n; i++)
#define MOD 1000000007

int main() {
  int x,y;
  cin >> x >> y;
  string grid[x];
  rep(i,x) cin >> grid[i];

  int cnt1[x][y];
  rep(i,x) rep(j,y) cnt1[i][j] = 0;
  int l,r,cnt;
  rep(i,x) {
    l = 0;
    cnt = 0;
    rep(j,y) {
      if (grid[i][j] == '#') {
        for(int z = l; z < j; z++) cnt1[i][z] = cnt;
        l = j+1;
        cnt = 0;
      }
      else cnt++;
    }
    for(int z = l; z < y; z++) cnt1[i][z] = cnt;
  }

  int cnt2[x][y];
  rep(i,x) rep(j,y) cnt2[i][j] = 0;
  rep(i,y) {
    l = 0;
    cnt = 0;
    rep(j,x) {
      if (grid[j][i] == '#') {
        for(int z = l; z < j; z++) cnt2[z][i] = cnt;
        l = j+1;
        cnt = 0;
      }
      else cnt++;
    }
    for(int z = l; z < x; z++) cnt2[z][i] = cnt;
  }

  int ans = 0;
  rep(i,x) {
    rep(j,y) {
      if (grid[i][j] != '#') ans = max(ans,cnt1[i][j]+cnt2[i][j]-1);
    }
  }
  cout << ans << endl;
  return 0;
}