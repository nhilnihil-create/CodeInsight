#include<bits/stdc++.h>
#define int long long
using namespace std;
int N,T,dp[6100];
pair<int,int> A[3100];
signed main(){
  cin>>N>>T;
  for(int i=0;i<=T+3000;i++)dp[i]=0;
  for(int i=0;i<N;i++)cin>>A[i].first>>A[i].second;
  sort(A,A+N);
  for(int i=0;i<N;i++){
    for(int j=T-1;j>=0;j--)dp[j+A[i].first]=max(dp[j+A[i].first],dp[j]+A[i].second);
  }
  int ans=0;
  for(int i=0;i<=T+3000;i++)ans=max(ans,dp[i]);
  cout<<ans<<endl;
}