#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int h, w, k;
  cin >> h >> w >> k;
  vector<string> c(h);
  rep(i,h) cin >> c[i];
  int ans = 0;
  rep(bi,1<<h)rep(bj,1<<w) {
    int cnt = 0;
    rep(i,h)rep(j,w) {
      if (bi>>i & 1) continue;
      if (bj>>j & 1) continue;
      if (c[i][j] == '#') cnt++;
    }
    if (cnt == k) ans++;
  }
  cout << ans << endl;
  return 0;
}