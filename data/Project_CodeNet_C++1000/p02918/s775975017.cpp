#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 100000000000;

signed main() {
  int N, K;
  cin >> N >> K;
  
  string S;
  cin >> S;
  
  int ans = 0;
  for( int i = 1; i < S.size(); i++ ){
    if( S.at(i) == S.at(i-1) ) ans++;
  }
  
  ans = min(ans+(2*K), N-1);
  cout << ans << endl;
  
}