#include <bits/stdc++.h>
using namespace std;

int main() {
  const int MOD = 1000000007;
  string L; cin >> L;
  int N = L.size();
  vector<vector<long long>> dp(N+1, vector<long long>(2, 0));
  dp.at(0).at(0) = 1;
  for (int i = 0; i < N; i++) {
    // 未満フラグ立っていないとき
    int D = L.at(i) - '0';
    if (D == 1) {
      dp.at(i+1).at(0) += dp.at(i).at(0) * 2 % MOD;
      dp.at(i+1).at(1) += dp.at(i).at(0);
    }
    else {
      dp.at(i+1).at(0) += dp.at(i).at(0);
    }
    // 未満フラグ立っているとき
    dp.at(i+1).at(1) += dp.at(i).at(1) * 3 % MOD;
  }
  cout << (dp.at(N).at(0) + dp.at(N).at(1)) % MOD << endl;
}