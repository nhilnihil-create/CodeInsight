#include<iostream>
#include<cstring>
using namespace std;

int main(){
  int r,c;
  int n;   
  int dp[1000][1000];
  while(1){
    cin>>r>>c;
    if(r==0)break;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++){
      int a,b;
      cin>>a>>b;
      dp[b-1][a-1]=0;
    }
    dp[c-1][r-1]=1;
    for(int i=c-1;i>=0;i--){
      for(int j=r-1;j>=0;j--){
	if(dp[i][j]==0)continue;
	if(i==c-1 && j==r-1)continue;
	if(i==c-1){
	  dp[i][j]=dp[i][j+1];
	}else if(j==r-1){
	  dp[i][j]=dp[i+1][j];
	}else{
	  dp[i][j]=dp[i+1][j]+dp[i][j+1];
	}
      }
    }
    // cout <<endl<< "Case"  << endl;
    // for(int i=c-1;i>-1;i--){
    //   for(int j=0;j<r;j++){
    // 	printf("%3d",dp[i][j]);
    //   }
    //   cout << endl;
    // }
    cout<<dp[0][0]<<endl;
  }
  return 0;
}