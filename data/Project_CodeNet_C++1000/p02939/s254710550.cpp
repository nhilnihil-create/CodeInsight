#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
const int MOD = 1000000007;
const int INF = 1e12;
using Graph = vector<vector<int>>;

signed main(){
  string S;
  cin >> S;
  int N = (int)S.size();
  if( N == 1 ){
    cout << 1 << endl;
    return 0;
  }

  vector<int> dp(N+10);
  dp[0] = 1;
  if( S[0] == S[1] ) dp[1] = 1;
  else dp[1] = 2;
  if( N == 2 ){
    cout << dp[1] << endl;
    return 0;
  }

  if( S[0] != S[1] && S[1] != S[2] ) dp[2] = 3;
  else dp[2] = 2;

  for( int i = 3; i < N; i++ ){
    if( S[i] == S[i-1] ) dp[i] = dp[i-3]+2;
    else dp[i] = dp[i-1]+1;
  }
  cout << dp[N-1] << endl;


}