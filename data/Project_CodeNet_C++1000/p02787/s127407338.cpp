#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
const int MOD = 1000000007;
const int INF = 1e12;
using Graph = vector<vector<int>>;

signed main(){
  int H, N;
  cin >> H >> N;
  vector<int> A(N);
  vector<int> B(N);
  for( int i = 0; i < N; i++ ) cin >> A[i] >> B[i];

  vector<int> dp(100000, INF);
  dp[0] = 0;
  for( int i = 0; i <= H; i++ ){
    for( int j = 0; j < N; j++ ){
      dp[i] = min(dp[i], dp[max(i-A[j], 0LL)]+B[j]);
    }
  }
  cout << dp[H] << endl;

}