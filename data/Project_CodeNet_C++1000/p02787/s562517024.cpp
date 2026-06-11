#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

const i64 inf_64 = (i64)1e18;

int main() {
  i64 H, N;
  cin >> H >> N;
  vector<i64> A(N), B(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i] >> B[i];
  }

  vector<i64> dp(H+1, inf_64);

  dp[H] = 0;

  for (int i = H; i > 0; i--) {
    for (int j = 0; j < N; j++) {
      i64 hp = max(i - A[j], (i64)0);
      dp[hp] = min(dp[hp], dp[i] + B[j]);
    }
  }
  cout << dp[0] << endl;
}