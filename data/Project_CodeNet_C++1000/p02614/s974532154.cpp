#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int H, W, K;
  cin >> H >> W >> K;
  vector<string> C(H);
  rep(h,H) cin >> C[h];

  int ans = 0;
  rep(bh, 1<<H) rep(bw, 1<<W) {
    int n_black = 0;
    rep(h,H) rep(w,W) {
      if (bh >> h & 1) continue;
      if (bw >> w & 1) continue;
      if (C[h][w] == '#') n_black++;
    }
    if (n_black == K) ans++;
  }
  cout << ans << endl;
  return 0;
}