#include <iostream>
#include <queue>

using namespace std;

int n;
int data[100];
long long dp[21][101];

main(){

  while(cin >> n){
    for(int i=0;i<n;i++){
      cin >> data[i];
    }

    for(int i=0;i<22;i++){
      for(int j=0;j<n;j++){
	dp[i][j]=0;
      }
    }
    dp[data[0]][0]++;
    for(int i=1;i<n;i++){
      for(int j=0;j<22;j++){
	if(dp[j][i-1]!=0){
	  int tmp;
	  tmp=j+data[i];
	  if(0<=tmp && tmp<=20){
	    dp[tmp][i]+=dp[j][i-1];
	  }
	  tmp=j-data[i];
	  if(0<=tmp && tmp<=20){
	    dp[tmp][i]+=dp[j][i-1];
	  }
	}
      }
    }
    

    cout << dp[data[n-1]][n-2] << endl;
  }
  return 0;
}