#include<bits/stdc++.h>
using namespace std;
int main(){
int N,T;
  cin>>N>>T;
  vector<int>A(N);
  vector<int>B(N);
  vector<pair<int,int>>C(N);
  for(int i=0;i<N;i++){
  int a,b; cin>>a>>b;
    pair<int,int>p(a,b);
    C.at(i)=p;
  }sort(C.begin(),C.end());
  for(int i=0;i<N;i++){
  A.at(i)=C.at(i).first;
    B.at(i)=C.at(i).second;
  }vector<int>D(N);D.at(N-1)=B.at(N-1);
  for(int i=N-2;0<=i;i--)
    D.at(i)=max(B.at(i),D.at(i+1));
  vector<vector<int>>dp(N+1,vector<int>(T+1,0));
  for(int i=1;i<=N;i++){
  for(int j=0;j<T;j++){
  if(j<A[i-1])
    dp[i][j]=dp[i-1][j];
    else
      dp[i][j]=max(dp[i-1][j],dp[i-1][j-A[i-1]]+B[i-1]);
  }
  }int ans=0;
  for(int i=0;i<N;i++)
    if(ans<dp[i][T-1]+D[i])
      ans=dp[i][T-1]+D[i];
  cout<<ans<<endl;
  return 0;
}