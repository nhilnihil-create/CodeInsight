#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
int main(){
  int N;
  cin>>N;
  pair<long long,long long> P[100001];
  P[0]=make_pair(-1000000000,0);
  for(int i=1;i<=N;i++){
    long long X,L;
    cin>>X>>L;
    P[i]=make_pair(X+L,L);
  }
  sort(P,P+N+1);
  int dp[100001]; //dp[i]:x<X[i]+L[i]
  dp[0]=0; dp[1]=1;
  for(int i=2;i<=N;i++){
    long long x=P[i].first-P[i].second*2;
    int left=0;
    int right=i;
    while(right-left!=1){
      int med=(left+right)/2;
      if(P[med].first<=x) left=med;
      else right=med;
    }
    dp[i]=max(dp[i-1],dp[left]+1);
  }
  cout<<dp[N]<<endl;
  
  return 0;
}