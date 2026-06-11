#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;
const int mod=1e9+7;

int main() {
  int H,N;
  cin>>H>>N;
  vector<int>A(N),B(N);
  for(int i=0;i<N;i++){
    cin>>A[i]>>B[i];
  }
  vector<int>dp(H+1,INF);
  dp[0]=0;
  for(int i=0;i<N;i++){
    for(int j=0;j<=H;j++){
      if(dp[j]==INF){continue;}
      chmin(dp[min(H,j+A[i])],dp[j]+B[i]);
    }
  }
  cout<<dp[H]<<endl;
  return 0;  
}