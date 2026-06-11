#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 1000000007;
const int INF = 1e15;
using Graph = vector<vector<int>>;

signed main(){
  int N;
  cin >> N;
  vector<int> A(N);
  for( int i = 0; i < N; i++ ) cin >> A.at(i);

  int ans = 0;
  int now = 1;
  for( int j = 0; j <= 60; j++ ){
    int k = 1LL << j;
    int one = 0;
    for( int i = 0; i < N; i++ ){
      if( A[i] & k ) one++;
    }

    ans += (one*(N-one))%MOD * now % MOD;
    ans %= MOD;
    now *= 2;
    now %= MOD;
  }
  cout << ans << endl;
}
