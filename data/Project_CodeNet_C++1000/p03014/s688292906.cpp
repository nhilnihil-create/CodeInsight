#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
int main() {
  int H, W;
  cin >> H >> W;
  vector<string> S(H);
  REP(i, H) cin >> S[i];
  vector<vector<int>> tate(H, vector<int>(W, 0)), yoko(H, vector<int>(W, 0));
  REP(i, H) {
    REP(j, W) {
      if (S[i][j] == '.') {
        if (j == 0) {
          yoko[i][j] = 1;
          continue;
        }
        yoko[i][j] = yoko[i][j - 1] + 1;
        continue;
      }
      if (j == 0) continue;
      for (int k = (j - 1); k >= 0; k--) {
        if (yoko[i][k] == 0) break;
        yoko[i][k] = yoko[i][j - 1];
      }
    }
    for (int k = W - 1; k >= 0; k--) {
      if (yoko[i][k] == 0) break;
      yoko[i][k] = yoko[i][W - 1];
    }
  }
  REP(i, W) {
    REP(j, H) {
      if (S[j][i] == '.') {
        if (j == 0) {
          tate[j][i] = 1;
          continue;
        }
        tate[j][i] = tate[j - 1][i] + 1;
        continue;
      }
      if (j == 0) continue;
      for (int k = j - 1; k >= 0; k--) {
        if (tate[k][i] == 0) break;
        tate[k][i] = tate[j - 1][i];
      }
    }
    for (int k = H - 1; k >= 0; k--) {
      if (tate[k][i] == 0) break;
      tate[k][i] = tate[H - 1][i];
    }
  }
  ll ans = 0;
  REP(i, H) REP(j, W) {
    ans = max(ans, (ll)tate[i][j] + (ll)yoko[i][j] - (ll)1);
  }
  cout << ans << endl;
}