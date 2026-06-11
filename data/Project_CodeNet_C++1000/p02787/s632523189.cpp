#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1e9+7;
const int INF=1001001001;

int main() {
  int H,N;
  cin>>H>>N;
  vector<int>A(N),B(N);
  for(int i=0;i<N;i++){
    cin>>A[i]>>B[i];
  }
  vector<int>dp(10005,INF);
  dp[H]=0;
  for(int j=H;j>=0;j--){
    for(int i=0;i<N;i++){
      chmin(dp[max(0,j-A[i])],dp[j]+B[i]);
    }
  }
  cout<<dp[0]<<endl;
  return 0;  
}