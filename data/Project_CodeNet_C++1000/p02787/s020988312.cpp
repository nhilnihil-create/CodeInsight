#include <bits/stdc++.h>
using namespace std;
static const int INF=100000000;

int main() {
  int H,N;
  cin>>H>>N;
  int A[N];
  int B[N];
  int maxA=0;
  for(int i=0;i<N;i++){
    cin>>A[i]>>B[i];
    maxA=max(maxA,A[i]);
  }
  
  int DP[H+maxA+1];
  for(int i=0;i<=H+maxA;i++){
    DP[i]=INF;
  }
  DP[0]=0;
  for(int i=0;i<=H+maxA;i++){
    for(int j=0;j<N;j++){
      if(i+A[j]<=H+maxA){
        DP[i+A[j]]=min(DP[i+A[j]],DP[i]+B[j]);
      }
    }
  }
  int ans=INF;
  for(int i=H;i<=H+maxA;i++){
    ans=min(ans,DP[i]);
  }
  cout<<ans<<endl;
  
}