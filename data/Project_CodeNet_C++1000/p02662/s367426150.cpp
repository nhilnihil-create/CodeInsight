#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const int INFint = 1e9+1;
const ll INFll = (ll)1e18+1;
ll MOD=998244353;

ll dp[3001][3001] = {0};
int main(){
  ll N;
  ll S;
  cin>>N>>S;
  vector<ll> A(N);
  for(int i(0);i<N;i++){
    cin>>A[i];
  }
  dp[0][0] = 1;
  for(int i(0);i<N;i++){
    for(int j(0);j<=S;j++){
      dp[i+1][j] += dp[i][j]*2;
      dp[i+1][j] %= MOD;
      if(j+A[i] <= S){
        dp[i+1][j+A[i]] += dp[i][j];
        dp[i+1][j+A[i]] %= MOD;
      }
    }
  }
  cout << dp[N][S]%MOD << endl;
  return 0;
}

