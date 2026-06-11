#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int H, W, K;
  cin >> H >> W >> K;
  vector<string> C(H);
  rep(i, H) cin >> C[i];

  int ans = 0;
  for (int bitH = 0; bitH < (1<<H); bitH++) {
    for (int bitW = 0; bitW < (1<<W); bitW++) {
      vector<string> D(H);
      rep(i, H) D[i] = C[i];
      rep(h, H) if (bitH & (1<<h)) rep(i, W) D[h][i] = 'R';
      rep(w, W) if (bitW & (1<<w)) rep(i, H) D[i][w] = 'R';
      int n_black = 0;
      rep(i, H) rep(j, W) if (D[i][j] == '#') n_black++;
      if (n_black == K) ans++;
    }
  }
  cout << ans << endl;
  return 0;
}