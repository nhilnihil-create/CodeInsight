#include <bits/stdc++.h>
using namespace std;

int main() {
  int INF = 100000001;
  int H, N;
  cin >> H >> N;
  
  vector<vector<int>> dp(N + 1, vector<int>(H + 1, INF));
  dp.at(0).at(0) = 0;
  for (int i = 1; i <= N; i++) {
    int A, B;
    cin >> A >> B;
    for (int j = 0; j <= H; j++) {
      dp.at(i).at(j) = min(dp.at(i - 1).at(j), dp.at(i).at(max(j - A, 0)) + B);
    }
  }
  
  int ans = dp.at(N).at(H);

  cout << ans << endl;
}