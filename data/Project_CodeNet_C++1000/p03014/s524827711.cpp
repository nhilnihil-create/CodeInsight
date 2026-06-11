// ABC 129 D Lamp

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int solve(int H, int W, vector<vector<char>> masu) {
  vector<vector<int>> ue(H, vector<int>(W));
  for (int j=0; j<W; j++){
    for (int i=H-1; i>=0; i--) {
      if (masu.at(i).at(j) == '#') {
        ue.at(i).at(j) = 0;
        continue;
      }
      if (i+1 >= H) {
        ue.at(i).at(j) = 1;
        continue;
      }
      ue.at(i).at(j) = ue.at(i+1).at(j) + 1;
    }
  }
  vector<vector<int>> shita(H, vector<int>(W));
  for (int j=0; j<W; j++){
    for (int i=0; i<H; i++) {
      if (masu.at(i).at(j) == '#') {
        shita.at(i).at(j) = 0;
        continue;
      }
      if (i-1 < 0) {
        shita.at(i).at(j) = 1;
        continue;
      }
      shita.at(i).at(j) = shita.at(i-1).at(j) + 1;
    }
  }
  vector<vector<int>> migi(H, vector<int>(W));
  for (int i=0; i<H; i++){
    for (int j=0; j<W; j++) {
      if (masu.at(i).at(j) == '#') {
        migi.at(i).at(j) = 0;
        continue;
      }
      if (j-1 < 0) {
        migi.at(i).at(j) = 1;
        continue;
      }
      migi.at(i).at(j) = migi.at(i).at(j-1) + 1;
    }
  }
  vector<vector<int>> hidari(H, vector<int>(W));
  for (int i=0; i<H; i++){
    for (int j=W-1; j>=0; j--) {
      if (masu.at(i).at(j) == '#') {
        hidari.at(i).at(j) = 0;
        continue;
      }
      if (j+1 >= W) {
        hidari.at(i).at(j) = 1;
        continue;
      }
      hidari.at(i).at(j) = hidari.at(i).at(j+1) + 1;
    }
  }
  int max = 0;
  for (int i=0; i<H; i++) {
    for (int j=0; j<W; j++) {
      int value = ue.at(i).at(j) + migi.at(i).at(j) + shita.at(i).at(j) + hidari.at(i).at(j) - 3;
      if (max < value) {
        max = value;
      }
    }
  }
  return max;
}

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> masu(H, vector<char>(W));
  for (int i=0; i<H; i++) {
    for (int j=0; j<W; j++) {
      cin >> masu.at(i).at(j);
    }
  }
  cout << solve(H, W, masu) << endl;
  return 0;
}

