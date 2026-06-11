//#include<bits/stdc++.h>
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<numeric>
#include<vector>
#include<set>
#include<map>
#include<unordered_map>
#include<stack>
#include<queue>
#include<list>
using namespace std;

#define MOD 1000000007

int main(){
  long long n,m;
  cin >> n >> m;
  long long s[n+1],t[m+1];
  for(int i=1;i<n+1;i++){
    cin >> s[i];
  }
  for(int i=1;i<m+1;i++){
    cin >> t[i];
  }
  long long sum[n+1][m+1];
  long long dp[n+1][m+1];
  for(int i=0;i<n+1;i++){
    for(int j=0;j<m+1;j++){
      sum[i][j] = 0;
      dp[i][j] = 0;
    }
  }
  dp[0][0] = 0;

  for(int i=1;i<n+1;i++){
    for(int j=1;j<m+1;j++){
      if(s[i] == t[j]){
        dp[i][j] = sum[i-1][j-1]+1;
      }
      else{
        dp[i][j] = 0;
      }
      dp[i][j] %= MOD;
      sum[i][j] = sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+dp[i][j];
      sum[i][j] %= MOD;
    }
  }
  long long ans = sum[n][m];
  ans += 1;
  ans %= MOD;
  ans += MOD;
  ans %= MOD;

  cout << ans << endl;


  return 0;
}