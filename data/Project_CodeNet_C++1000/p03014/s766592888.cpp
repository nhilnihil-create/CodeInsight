#include <bits/stdc++.h>
using namespace std;
int main(){
  int H, W;
  cin >> H >> W;
  vector<vector<char>> S(H + 2, vector<char>(W + 2, '#'));
  for (int i = 1; i <= H; i++){
    for (int j = 1; j <= W; j++){
      cin >> S[i][j];
    }
  }
  vector<vector<int>> R(H + 2, vector<int>(W + 2, 0));
  for (int i = 0; i < H + 2; i++){
    for (int j = W; j >= 0; j--){
      if (S[i][j] == '#'){
        R[i][j] = 0;
      } else {
        R[i][j] = R[i][j + 1] + 1;
      }
    }
  }
  vector<vector<int>> L(H + 2, vector<int>(W + 2, 0));
  for (int i = 0; i < H + 2; i++){
    for (int j = 1; j < W + 2; j++){
      if (S[i][j] == '#'){
        L[i][j] = 0;
      } else {
        L[i][j] = L[i][j - 1] + 1;
      }
    }
  }
  vector<vector<int>> D(H + 2, vector<int>(W + 2, 0));
  for (int i = 0; i < W + 2; i++){
    for (int j = H; j >= 0; j--){
      if (S[j][i] == '#'){
        D[j][i] = 0;
      } else {
        D[j][i] = D[j + 1][i] + 1;
      }
    }
  }
  vector<vector<int>> U(H + 2, vector<int>(W + 2, 0));
  for (int i = 0; i < W + 2; i++){
    for (int j = 1; j < H + 2; j++){
      if (S[j][i] == '#'){
        U[j][i] = 0;
      } else {
        U[j][i] = U[j - 1][i] + 1;
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= H; i++){
    for (int j = 1; j <= W; j++){
      ans = max(ans, R[i][j] + L[i][j] + D[i][j] + U[i][j] - 3);
    }
  }
  cout << ans << endl;
}