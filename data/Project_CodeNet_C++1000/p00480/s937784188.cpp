#include<iostream>
#include<vector>
using namespace std;
#define MAX 20
int main()
{
  int N;

  cin>>N;

  vector<int>n(N);
  vector< vector<long long int> >dp(N,vector<long long int>(MAX+1,0));

  for(int i=0;i<N;i++)cin>>n[i];

  dp[0][n[0]]=1;
  for(int i=1;i<N;i++){
    for(int j=0;j<=MAX;j++){
      if(j+n[i]<=MAX){
	dp[i][j]+=dp[i-1][j+n[i]];
      }
      if(j-n[i]>=0){
	dp[i][j]+=dp[i-1][j-n[i]];
      }
    }
  }

  cout<<dp[N-2][n[N-1]]<<endl;
}