#include <bits/stdc++.h>
using namespace std;

int main() {

  int H, W;
  cin >> H >> W;

  vector<string> S(H);
  for (int i = 0; i < H; i++){
    cin >> S[i];
  }

  vector<vector<int>> w(H,vector<int>(W));
  vector<vector<int>> countW(H);
  for (int i = 0; i < H; i++){
    int count = 0;
    int current = 0;
    for (int j = 0; j < W; j++){
      if (S[i][j] == '.') {
        w[i][j] = count;
        current++;
        if (j == W - 1) {
          countW[i].push_back(current);
        }
      } else {
        countW[i].push_back(current);
        current = 0;
        count++;
      }
    }
  }

  vector<vector<int>> h(W,vector<int>(H));
  vector<vector<int>> countH(W);
  for (int i = 0; i < W; i++){
    int count = 0;
    int current = 0;
    for (int j = 0; j < H; j++){
      if (S[j][i] == '.') {
        h[i][j] = count;
        current++;
        if (j == H - 1) {
          countH[i].push_back(current);
        }
      } else {
        countH[i].push_back(current);
        current = 0;
        count++;
      }
    }
  }

  int answer = 0;

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (S[i][j] == '.') {
        int ans = countW[i][w[i][j]] + countH[j][h[j][i]] - 1;
        answer = max(answer, ans);
      }
    }
  }

  cout << answer << endl;
  
  return 0;
}