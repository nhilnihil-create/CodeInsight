#include<bits/stdc++.h>
using namespace std;

const int mod=1e9+7;

void add(int& a,int b)
{
   a=(a+b)%mod;
}

int main()
{
   int N,M; cin>>N>>M;
   vector<int> a(N),b(M);
   for(int i=0;i<N;i++) cin>>a[i];
   for(int i=0;i<M;i++) cin>>b[i];

   vector<vector<int>> dp(N+1,vector<int>(M+1));
   for(int j=0;j<=M;j++) dp[0][j]=1;
   for(int i=0;i<=N;i++) dp[i][0]=1;
   for(int i=0;i<N;i++) for(int j=0;j<M;j++){
      if(a[i]==b[j]) add(dp[i+1][j+1],dp[i][j]);
      add(dp[i+1][j+1],dp[i+1][j]);
      add(dp[i+1][j+1],dp[i][j+1]);
      add(dp[i+1][j+1],mod-dp[i][j]);
   }
   cout<<dp[N][M]<<endl;
   return 0;
}