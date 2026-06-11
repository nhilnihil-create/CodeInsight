#include <iostream>

using namespace std;

main(){
  long long dp[31];
  for(int i=0;i<31;i++){
    dp[i]=0;
  }
  dp[0]=1;
  for(int i=0;i<31;i++){
    int t=i+1;
    if(t<31) dp[t]+=dp[i];
    t++;
    if(t<31) dp[t]+=dp[i];
    t++;
    if(t<31) dp[t]+=dp[i];
  }

  int n;
  while(1){
    cin >> n;
    if(n==0) break;

    if(dp[n]%3650==0){
      cout << dp[n]/3650 << endl;
    }else{
      cout << dp[n]/3650+1 << endl;
    }
  }
  return 0;
}