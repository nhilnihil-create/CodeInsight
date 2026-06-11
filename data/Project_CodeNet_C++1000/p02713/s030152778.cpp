#include <bits/stdc++.h>
using namespace std;

int main() {
  int K, S = 0;
  cin >> K;
  vector<vector<vector<int>>> v(K+1, vector<vector<int>>(K+1, vector<int>(K+1, 1)));
  for(int i = 2;i < K + 1;i++) {
    for(int j = i;j < K + 1;j += i) {
      for(int k = i;k < K + 1;k += i) {
        for(int l = i;l < K + 1;l += i) v[l][j][k] = i;
      }
    }
  }
  for(int i = 1;i < K + 1;i++) {
    for(int j = 1;j < K + 1;j++) {
      for(int k = 1;k < K + 1;k++) {
        S += v[i][j][k];
      }
    }
  }
  cout << S << endl;
}