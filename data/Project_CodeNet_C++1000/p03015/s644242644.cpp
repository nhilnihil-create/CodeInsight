#include <bits/stdc++.h> 

using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;

#define INF LONG_MAX
#define MOD 1000000007
#define rng(a) a.begin(),a.end()
#define rrng(a) a.end(),a.begin()
#define endl "\n"

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  string L;
  cin>>L;
  int N=L.size();
  vector<vector<ll>>dp(N,vector<ll>(2,0));
  dp[0][0]=2;
  dp[0][1]=1;
  for(int i=1;i<N;i++){
    if(L[i]=='1'){
      dp[i][0]=(dp[i-1][0]*2)%MOD;
      dp[i][1]=(dp[i-1][0]+dp[i-1][1]*3)%MOD;
    }
    if(L[i]=='0'){
      dp[i][0]=dp[i-1][0];
      dp[i][1]=(dp[i-1][1]*3)%MOD;
    }
  }
  cout<<(dp[N-1][0]+dp[N-1][1])%MOD<<endl;
  return 0;
}
