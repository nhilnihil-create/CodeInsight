#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,S;
  cin >> N >> S;
  int A;
  vector<vector<long long>> dp(N+1,vector<long long>(S+1,0));
  dp[0][0]=1;
  for(int loop=0;loop<N;loop++){
    cin >> A;
    for(int loop2=0;loop2<=S;loop2++){
      dp[loop+1][loop2]+=dp[loop][loop2]*2;
      if(loop2+A<=S){
        dp[loop+1][loop2+A]+=dp[loop][loop2];
      }
      dp[loop+1][loop2]%=998244353;
    }
  }
  cout << dp[N][S] << endl;
  return 0;
}