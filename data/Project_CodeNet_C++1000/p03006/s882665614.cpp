#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 10e18;

signed main() {
  int N;
  cin >> N;
  
  vector<int> X(N);
  vector<int> Y(N);
  for( int i = 0; i < N; i++ ) cin >> X.at(i) >> Y.at(i);
  
  if( N == 1 ){
    cout << 1 << endl;
    return 0;
  }
  
  int ans = INF;
  for( int i = 0; i < N; i++ ){ //1つ目
    for( int j = i+1; j < N; j++ ){ //2つ目
      //P,Qを決める
      int P = X.at(j)-X.at(i);
      int Q = Y.at(j)-Y.at(i);
      int now = 0;
      for( int k = 0; k < N; k++ ){
        for( int l = 0; l < N; l++ ){
          if( k == l ) continue;
          int dx = X.at(l)-X.at(k);
          int dy = Y.at(l)-Y.at(k);
          if( P == dx && Q == dy ) now++;
        }
      }
      ans = min(ans, N-now);
    }
  }
  cout << ans << endl;
}
