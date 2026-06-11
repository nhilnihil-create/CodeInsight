#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, t;
  cin >> n >> t;
  vector<vector<int>> dp(t, vector<int>(2,0));
  for(int i=0; i<n; ++i){
    int a, b;
    cin >> a >> b;
    for(int j=t-1; j>=0; --j){
      dp[j][0] = max(dp[j][0], dp[j][1]+b);
      if(j>=a)dp[j][0] = max(dp[j][0], dp[j-a][0]+b);
      if(j>=a)dp[j][1] = max(dp[j][1], dp[j-a][1]+b);
    }
  }
  cout << dp[t-1][0] << endl;
}