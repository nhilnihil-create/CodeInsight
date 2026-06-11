#include<bits/stdc++.h>
using namespace std;
using ll=long long;


const int MOD=1e9+7;

int dp[2010];

int main(){
  int s;
  cin >> s;
  dp[0]=1;
  dp[1]=0;
  dp[2]=0;
  for(int i=3;i<=s;++i){
    dp[i]=dp[i-1]+dp[i-3];
    dp[i]%=MOD;
  }
  cout << dp[s] << endl;
  return 0;
}
