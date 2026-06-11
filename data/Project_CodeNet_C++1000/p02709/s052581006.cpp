#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  vector<pair<int,int>>A(N);
  for(int i=0;i<N;i++){
    int a;
    cin>>a;
    A[i]={a,i};
  }
  sort(A.rbegin(),A.rend());
  vector<vector<long>>dp(2020,vector<long>(2020,-(1L<<60)));
  dp.at(0).at(0)=0;
  for(int i=0;i<N;i++){// i:詰める個数-1
    long k=A[i].first;// 活発度
    long r=A[i].second;// 移動前の位置
    for(int x=0;x<=i;x++){// x:確定している左に詰める個数、かつ左に移動後の位置
      long y=i-x;// y:確定している右に詰める個数
      long z=N-1-y;// z:右に移動後の位置
      dp[x+1][y]=max(dp[x+1][y],dp[x][y]+abs(r-x)*k);
      dp[x][y+1]=max(dp[x][y+1],dp[x][y]+abs(r-z)*k);
      // cout<<"(x,y)="<<"("<<x<<","<<y<<")"<<endl;
      // cout<<"dp[x][y]:"<<dp[x][y]<<endl;
      // cout<<"dp[x+1][y]:"<<dp[x+1][y]<<endl;
      // cout<<"dp[x][y+1]:"<<dp[x][y+1]<<endl;
    }
  }
  long ans=-(1L<<60);
  for(int i=0;i<=N;i++)ans=max(ans,dp[i][N-i]);
  cout<<ans<<endl;
}
