#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> data(H);
  for(int i = 0; i < H; i++) {
    cin >> data.at(i);
  }
  vector<vector<int>> L(H, vector<int> (W));
  vector<vector<int>> R(H, vector<int> (W));
  vector<vector<int>> U(H, vector<int> (W));
  vector<vector<int>> D(H, vector<int> (W));
  for(int i = 0; i < H; i++) {
    for(int j = 0; j < W; j++) {
      if(data.at(i).at(j) == '#') {
        L.at(i).at(j) = 0;
      }
      else if(j == 0) {
        L.at(i).at(j) = 1;
      }
      else {
        L.at(i).at(j) = L.at(i).at(j - 1) + 1;
      }
    }
  }
  for(int i = 0; i < H; i++) {
    for(int j = W - 1; j >= 0; j--) {
      if(data.at(i).at(j) == '#') {
        R.at(i).at(j) = 0;
      }
      else if(j == W - 1) {
        R.at(i).at(j) = 1;
      }
      else {
        R.at(i).at(j) = R.at(i).at(j + 1) + 1;
      }
    }
  }
  for(int j = 0; j < W; j++) {
    for(int i = 0; i < H; i++) {
      if(data.at(i).at(j) == '#') {
        U.at(i).at(j) = 0;
      }
      else if(i == 0) {
        U.at(i).at(j) = 1;
      }
      else {
        U.at(i).at(j) = U.at(i - 1).at(j) + 1;
      }
    }
  }
  for(int j = 0; j < W; j++) {
    for(int i = H - 1; i >= 0; i--) {
      if(data.at(i).at(j) == '#') {
        D.at(i).at(j) = 0;
      }
      else if(i == H - 1) {
        D.at(i).at(j) = 1;
      }
      else {
        D.at(i).at(j) = D.at(i + 1).at(j) + 1;
      }
    }
  }
  int ans = 0;
  for(int i = 0; i < H; i++) {
    for(int j = 0; j < W; j++) {
      int sum = L.at(i).at(j) + R.at(i).at(j) + U.at(i).at(j) + D.at(i).at(j) - 3;
      if(sum > ans) {
        ans = sum;
      }
    }
  }
  cout << ans << endl;
}