#include <bits/stdc++.h>
using namespace std;
#define rep(i, ss, ee) for (int i = ss; i < ee; ++i)

int H, W, K;
vector<string> v;
void input() {
  cin >> H >> W >> K;
  v.resize(H);
  for (auto &s : v) { cin >> s; }
}

void solve() {
  int ans = 0;
  for (int h = 0; h < (1 << H); h++) {
    for (int w = 0; w < (1 << W); w++) {
      int cnt = 0;
      rep(i, 0, H) {
        rep(j, 0, W) {
          if (h >> i & 1) continue;
          if (w >> j & 1) continue;
          if (v[i][j] == '#') cnt++;
        }
      }
      if (cnt == K) ans++;
    }
  }
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  input();
  solve();
}