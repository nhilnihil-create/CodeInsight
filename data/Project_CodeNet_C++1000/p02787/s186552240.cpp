#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;

int main() {
  int H,N;
  cin>>H>>N;
  vector<int>A(N),B(N);
  for(int i=0;i<N;i++){
    cin>>A[i]>>B[i];
  }
  vector<vector<int64_t>>dp(N+1,vector<int64_t>(H+1,INF));
  dp[0][0]=0;
  for(int i=0;i<N;i++){
    for(int j=0;j<=H;j++){
      chmin(dp[i+1][j],dp[i][j]);
      chmin(dp[i+1][min(j+A[i],H)],dp[i+1][j]+B[i]);
    }
  }
  cout<<dp[N][H]<<endl;
  return 0;
}