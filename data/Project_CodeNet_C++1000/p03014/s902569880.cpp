#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> S(H);
  for (int i = 0; i < H; i++) cin >> S[i];
  vector<vector<int>> L(H, vector<int>(W));
  vector<vector<int>> R(H, vector<int>(W));
  vector<vector<int>> U(H, vector<int>(W));
  vector<vector<int>> D(H, vector<int>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (S[i][j] == '.') {
        if (j == 0) L[i][j] = 1;
        else L[i][j] = L[i][j-1] + 1;
      }
      else L[i][j] = 0;
    }
    for (int j = W-1; j >= 0; j--) {
      if (S[i][j] == '.') {
        if (j == W-1) R[i][j] = 1;
        else R[i][j] = R[i][j+1] + 1;
      }
      else R[i][j] = 0;
    } 
  }
  for (int i = 0; i < W; i++) {
    for (int j = 0; j < H; j++) {
      if (S[j][i] == '.') {
        if (j == 0) U[j][i] = 1;
        else U[j][i] = U[j-1][i] + 1;
      }
      else U[j][i] = 0;
    }
    for (int j = H-1; j >= 0; j--) {
      if (S[j][i] == '.') {
        if (j == H-1) D[j][i] = 1;
        else D[j][i] = D[j+1][i] + 1;
      }
      else D[j][i] = 0;
    }
  }

  int res = 1;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      int tmp = L[i][j] + R[i][j] + U[i][j] + D[i][j] - 3;
      if (tmp > res) res = tmp;
    }
  }
  cout << res;
}
