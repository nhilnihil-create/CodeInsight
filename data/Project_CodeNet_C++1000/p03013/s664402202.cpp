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
  vector<bool>a(N+1,false);
  for(int i=0;i<M;i++){
    int x;
    cin>>x;
    a[x]=true;
  }
  vector<int64_t>dp(N+1);
  dp[0]=1;
  for(int i=0;i<=N;i++){
    if(a[i]){continue;}
    if(i<=N-1){dp[i+1]+=dp[i];dp[i+1]%=mod;}
    if(i<=N-2){dp[i+2]+=dp[i];dp[i+2]%=mod;}
    dp[i]%=mod;
  }
  cout<<dp[N]<<endl;
  return 0;  
}