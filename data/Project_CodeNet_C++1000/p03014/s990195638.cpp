#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> V(H, vector<char>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> V.at(i).at(j);
    }
  }
  vector<vector<int>> WC(H, vector<int>(W));
  vector<vector<int>> HC(H, vector<int>(W));
  for (int i = 0, cnt = 0; i < H; i++) {
    V.at(i).push_back('#');
    for (int j = 0; j < W + 1; j++) {
      if (V.at(i).at(j) == '.') cnt++;
      else if (cnt) {
        for (int k = j - cnt; k < j; k++) WC.at(i).at(k) = cnt;
        cnt = 0;
      }
    }
    V.at(i).pop_back();
  }
  vector<char> tmp(W, '#');
  V.push_back(tmp);
  for (int j = 0, cnt = 0; j < W; j++) {
    for (int i = 0; i < H + 1; i++) {
      if (V.at(i).at(j) == '.') cnt++;
      else if (cnt) {
        for (int k = i - cnt; k < i; k++) HC.at(k).at(j) = cnt;
        cnt = 0;
      }
    }
  }
  V.pop_back();
  int ans = 0;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      ans = max(ans, WC.at(i).at(j) + HC.at(i).at(j));
    }
  }
  cout << ans - 1 << "\n";
}