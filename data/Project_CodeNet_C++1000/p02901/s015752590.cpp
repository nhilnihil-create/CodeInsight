#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1e9+7;
const int INF=1001001001;


int main() {
  int N,M;
  cin>>N>>M;
  vector<int64_t>A(M);
  vector<int64_t>C(M);
  for(int i=0;i<M;i++){
    cin>>C[i];
    int b;
    cin>>b;
    for(int j=0;j<b;j++){
      int c;
      cin>>c;
      A[i]|=(1<<(c-1));
    }
  }
  vector<int64_t>dp(1<<N,INF);
  dp[0]=0;
  for(int i=0;i<M;i++){
    for(int j=0;j<(1<<N);j++){
      if(dp[j]==INF){continue;}
      chmin(dp[j|A[i]],dp[j]+C[i]);
    }
  }
  if(dp[(1<<N)-1]==INF){cout<<-1<<endl;}
  else{cout<<dp[(1<<N)-1]<<endl;}
  return 0;  
}