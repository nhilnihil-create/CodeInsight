#include <bits/stdc++.h>
using namespace std;
int mod = 1000000007;
long long dp[100005];

int main() {
  int n,m;
  cin >> n >>m;
  int st[m+1];
  int tmp;
  
  for(int i = 0; i < m;i++){
    cin >> tmp;
    dp[tmp] = -1;
  }
  dp[0] = 1;
  if(dp[1] != -1){dp[1] = 1;}
  else{dp[1] = 0;}
  for(int i = 2; i < n+1;i++){
    if(dp[i] == -1){
      dp[i] = 0;
    }else{
      dp[i] = dp[i-1] + dp[i-2];
      dp[i] %= mod;
      //cout << dp[i] << endl;
    }
  }

  cout << dp[n] << endl;
}
