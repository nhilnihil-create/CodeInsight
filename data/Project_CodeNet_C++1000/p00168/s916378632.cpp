#include<iostream>
using namespace std;
int dp[50];
int main(){
  int n;
  while(cin>>n,n){
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=n;i++){
      dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
    }
    cout<<(dp[n]+3649)/3650<<endl;
  }
  return 0;
}