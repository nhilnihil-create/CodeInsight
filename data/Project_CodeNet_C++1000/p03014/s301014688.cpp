#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int L[2000][2000];
int R[2000][2000];
int U[2000][2000];
int D[2000][2000];

int main() {
  // 4つのグリッドを用意
  int H, W;
  cin >> H >> W;
  vector<string> S(H);
  rep(i, H) cin >> S[i];
  int ans = 0;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (S[i][j] == '#') L[i][j] = 0;
      else {
        L[i][j]++;
        if (j < W-1) L[i][j+1] = L[i][j];
      }
    }
  }
  for (int i = 0; i < H; i++) {
    for (int j = W-1; j >= 0; j--) {
      if (S[i][j] == '#') R[i][j] = 0;
      else {
        R[i][j]++;
        if (j > 0) R[i][j-1] = R[i][j];
      }
    }
  }
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (S[i][j] == '#') U[i][j] = 0;
      else {
        U[i][j]++;
        if (i < H-1) U[i+1][j] = U[i][j];
      }
    }
  }
  for (int i = H-1; i >= 0; i--) {
    for (int j = 0; j < W; j++) {
      if (S[i][j] == '#') D[i][j] = 0;
      else {
        D[i][j]++;
        if (i > 0) D[i-1][j] = D[i][j];
      }
    }
  }
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      int temp = L[i][j] + R[i][j] + U[i][j] + D[i][j] - 3;
      if (temp > ans) {
        ans = temp;
      }
    }
  }
  cout << ans << '\n';
  return 0;

}