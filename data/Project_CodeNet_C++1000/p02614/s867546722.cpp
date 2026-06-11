//ビット全探索

#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int inf{int(1e9)};
int main(void){
  int H, W, K;
  cin >> H >> W >> K;
  vector <string> c(H);
  rep(i,H) cin >> c[i];

  int ans = 0;
  rep(is,1<<H)rep(js,1<<W){
    int cnt = 0;
    rep(i,H)rep(j,W){
      if (is>>i&1) continue;
      if (js>>j&1) continue;
      if (c[i][j] == '#') cnt ++;
    }
    if (cnt == K) ans ++;
  }
  cout << ans << endl;
}
