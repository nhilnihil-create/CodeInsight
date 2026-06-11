#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
const int MOD = 1000000007;
const int INF = 1e14;
using Graph = vector<vector<int>>;

signed main(){
  int N, K, A, B, C;
  cin >> N >> K >> A >> B >> C;
  string T;
  cin >> T;

  int ans = 0;
  vector<bool> win(N);
  for( int i = 0; i < N; i++ ){
    int now = -1;
    if( T[i] == 'r' ) now = C;
    else if( T[i] == 's' ) now = A;
    else now = B;

    if( i < K ){
      ans += now;
      win[i] = 1;
    }else if( T[i] != T[i-K] ){
      ans += now;
      win[i] = 1;
    }else if( win[i-K] == 0 ){
      ans += now;
      win[i] = 1;
    }
  }
  cout << ans << endl;


}
