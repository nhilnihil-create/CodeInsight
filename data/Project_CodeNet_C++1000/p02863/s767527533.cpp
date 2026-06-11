#include<iostream>
#include<vector>
using namespace std;

int main(){
  int N, T;
  cin >> N >> T;

  vector<pair<int, int>> AB(N);
  for(auto& ab: AB){
    cin >> ab.first >> ab.second;
  }
  sort(AB.begin(), AB.end());

  int ans = 0;
  // dp[n][t] := With AB[0: n) and within t minutes,
  // one can eat dp[n][t] delicious food
  // ans = dp[n][T - 1] + B[n - 1]
  vector<vector<int>> dp(N + 1, vector<int>(T, 0));
  for(int n = 0; n < N; n++){
    ans = max(ans, dp[n][T - 1] + AB[n].second);
    for(int t = 0; t < T; t++){
      int a = AB[n].first, b = AB[n].second;
      dp[n + 1][t] = dp[n][t];
      if(t - 1 >= 0){
        dp[n + 1][t] = max(dp[n + 1][t], dp[n][t - 1]);
      }
      if(t - a >= 0){
        dp[n + 1][t] = max(dp[n + 1][t], dp[n][t - a] + b);
      }
    }
  }
  cout << ans << endl;
   

}
