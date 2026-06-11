#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const ll Mod = 998244353;
const int MAX = 510000;
const double PI = 3.14159265358979;
const vector<int> dx = {1, 0};
const vector<int> dy = {0, 1};

int main() {
  int H, N;
  cin >> H >> N;
  vector<int> A(N), B(N);
  for (int i=0; i<N; i++) cin >> A[i] >> B[i];
  vector<vector<ll>> dp(N+1, vector<ll>(H+1, INT_MAX));
  dp[0][0] = 0;
  for (int i=0; i<N; i++) {
    for (int j=0; j<=H; j++) {
      dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
      dp[i+1][min(j+A[i], H)] = min(dp[i+1][min(j+A[i], H)], dp[i+1][j]+B[i]);
    }
  }
  cout << dp[N][H] << endl;
  return 0;
}