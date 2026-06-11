#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 1000000007;
using Graph = vector<vector<int>>;

signed main() {
  int N;
  cin >> N;
  
  vector<int> cnt(100010);
  cnt.at(0) = 3;
  int ans = 1;
  for( int i = 0; i < N; i++ ){
    int A;
    cin >> A;
    ans *= cnt.at(A);
    ans %= MOD;
    cnt.at(A)--;
    cnt.at(A+1)++;
  }
  if( ans >= 0 ) cout << ans << endl;
  else cout << 0 << endl;
  
}