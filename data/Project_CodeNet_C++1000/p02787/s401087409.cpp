#include <bits/stdc++.h>
using namespace std;
 
int main () {
  int H, N;
  cin >> H >> N;
  vector<vector<int>> M(N, vector<int>(2));
  int K = 1000000000;
  for (int i = 0; i < N; i++) {
    cin >> M.at(i).at(0) >> M.at(i).at(1);
    K = min(K, M.at(i).at(1));
  }
  sort(M.begin(), M.end());
  vector<int> DP(H + 1, 1000000000);
  for (int i = 1; i < min(M.at(0).at(0), H + 1); i++) {
    DP.at(i) = K;
  }
  DP.at(0) = 0;
  for (int i = 0; i <= H; i++) {
    for (int j = 0; j < N; j++) {
      if (i >= M.at(j).at(0)) {
        DP.at(i) = min(DP.at(i), DP.at(i - M.at(j).at(0)) + M.at(j).at(1));
      }
      else {
        DP.at(i) = min(DP.at(i), M.at(j).at(1));
      }
    }
  }
  cout << DP.at(H) << endl;
}