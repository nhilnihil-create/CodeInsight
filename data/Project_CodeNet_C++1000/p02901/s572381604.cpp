#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
const int MOD = 1000000007;
const int INF = 1e12;
using Graph = vector<vector<int>>;

signed main(){
  int N, M;
  cin >> N >> M;
  vector<int> A(M);
  vector<int> B(M);
  vector<pair<int, int>> K(M);
  for( int i = 0; i < M; i++ ){
    cin >> A[i] >> B[i];
    int bit = 0;
    for( int j = 0; j < B[i]; j++ ){
      int C;
      cin >> C;
      C--;
      bit |= 1<<C;
    }
    K[i] = {bit, A[i]};
  }

  //bitで開けられる宝箱を表す
  vector<int> dp(1<<N, INF);
  dp[0] = 0;
  for( int i = 0; i < 1<<N; i++ ){
    for( int j = 0; j < M; j++ ){
      int s = i | K[j].first;
      dp[s] = min(dp[s], dp[i]+K[j].second);
    }
  }

  if( dp.back() >= INF ) cout << -1 << endl;
  else cout << dp.back() << endl;

}
