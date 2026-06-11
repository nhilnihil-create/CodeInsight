#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, D;
  cin >> N >> D;
  vector<vector<int>> X(N, vector<int>(D));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < D; j++) {
      cin >> X.at(i).at(j);
    }
  }
  int ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      int64_t memo = 0;
      for (int k = 0; k < D; k++) {
        memo += (X.at(i).at(k) - X.at(j).at(k)) * (X.at(i).at(k) - X.at(j).at(k));
      }
      int a = sqrt(memo);
      if (sqrt(memo) == a) {
        ans++;
      }
    }
  }
  cout << ans << endl;       
}