#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int MOD = 1000000007;

int main(){
  ll N, M;
  cin >> N >> M;
 
  vector<bool> is_safe;
  is_safe.assign(N+1, true);
  
  for(int i=0; i<M; i++){
    int a; cin >> a;
    is_safe[a] = false;
  }
  
  vector<int> dp(N+1, 0);
  
  dp[0] = 1;
  if(is_safe[1]) dp[1] = 1;
  
  
  for(int i=2; i<=N; i++){
    if(is_safe[i-1]) dp[i] += dp[i-1];
    if(is_safe[i-2]) dp[i] += dp[i-2];
    dp[i] %= MOD;
  
  }
  
  cout << dp[N] << endl;
 
  return 0;
}