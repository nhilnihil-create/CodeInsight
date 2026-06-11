#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> S(H, vector<char>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> S.at(i).at(j);
    }
  }
  vector<vector<int>> DP(H, vector<int>(W, 1e9));
  DP.at(0).at(0) = (S.at(0).at(0) == '#') ? 1 : 0;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (i) {
        int flip = (S.at(i - 1).at(j) == '.' && S.at(i).at(j) == '#');
        DP.at(i).at(j) = min(DP.at(i).at(j), DP.at(i - 1).at(j) + flip);
      }
      if (j) {
        int flip = (S.at(i).at(j - 1) == '.' && S.at(i).at(j) == '#');
        DP.at(i).at(j) = min(DP.at(i).at(j), DP.at(i).at(j - 1) + flip);
      }
    }
  }
  cout << DP.at(H - 1).at(W - 1) << "\n";
}