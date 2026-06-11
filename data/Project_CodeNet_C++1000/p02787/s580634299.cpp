#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef std::pair<int,int> pair2;
typedef std::pair<int,pair2> pair3;
const ll INF = 1LL<<60;

int main(){
    ll H,N;
  cin >>H>>N;
  ll A[N],B[N];
  for(ll i=0;i<N;i++){
  cin >>A[i]>>B[i];
  }
ll dp[H+1];
  dp[0]=0;
  for(ll i=1;i<H+1;i++){dp[i]=1LL<<50;}

  for(ll i=0;i<H+1;i++){
  for(ll j=0;j<N;j++){
  if(i+A[j]>=H){dp[H]=min(dp[H],dp[i]+B[j]);continue;}
  dp[i+A[j]]=min(dp[i+A[j]],dp[i]+B[j]);
  }
}      
  
  
  cout<<dp[H]<<endl;
  
}
