#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int H, W; cin >> H >> W;
  vector<string> F(H);
  for (int i=0; i<H; i++) cin >> F[i];
  
  vector<vector<int>> L(H, vector<int>(W));
  vector<vector<int>> R(H, vector<int>(W));
  vector<vector<int>> U(H, vector<int>(W));
  vector<vector<int>> D(H, vector<int>(W));
  
  for (int i=0; i<H; i++) {
    for (int j=0; j<W; j++) {
      // about L
      if (F[i][j] == '#') {
        L[i][j] = 0;
      } else {
        if (j == 0) {
          L[i][j] = 1;
        } else {
          L[i][j] = L[i][j-1] + 1;
        }
      }
      
      // about R
      if (F[i][W-(j+1)] == '#') {
        R[i][W-(j+1)] = 0;
      } else {
        if (j == 0) {
          R[i][W-(j+1)] = 1;
        } else {
          R[i][W-(j+1)] = R[i][W-j] + 1;
        }
      }
      
      // about U
      if (F[i][j] == '#') {
        U[i][j] = 0;
      } else {
        if (i == 0) {
          U[i][j] = 1;
        } else {
          U[i][j] = U[i-1][j] + 1;
        }
      }
      
      // about D
      if (F[H-(i+1)][j] == '#') {
        D[H-(i+1)][j] = 0;
      } else {
        if (i == 0) {
          D[H-(i+1)][j] = 1;
        } else {
		  D[H-(i+1)][j] = D[H-i][j] + 1;
        }
      }
    }
  }
  
  int ans = 0;
  for (int i=0; i<H; i++) {
    for (int j=0; j<W; j++) {
      int tmp = L[i][j] + R[i][j] + U[i][j] + D[i][j] - 3;
      if (ans < tmp) ans = tmp;
    }
  }
  
  cout << ans << endl;
  return 0;
}