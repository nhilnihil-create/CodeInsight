#include <bits/stdc++.h>
using namespace std;
  
int main() {
  int n,m;
  cin>>n>>m;
  long long a[m];
  for(int i=0;i<m;i++) cin>>a[i];
  long long dp[n+1];
  dp[0]=1;
  int j=0;
  if(a[0]==1) {
    dp[1]=0;
    if(j<m-1) j++;
  }
  else dp[1]=1;
  for(int i=2;i<=n;i++){
    if(a[j]==i){
      dp[i]=0;
      if(j<m-1) j++;
    }
    else{
      dp[i]=dp[i-1];
      dp[i]%=1000000007;
      dp[i]+=dp[i-2];
      dp[i]%=1000000007;
    }
  }
  cout<<dp[n]<<endl;
}
