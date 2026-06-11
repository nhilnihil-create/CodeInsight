#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 1000000007;
using Graph = vector<vector<int>>;

signed main() {
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  vector<int> F(N);
  for( int i = 0; i < N; i++ ) cin >> A.at(i);
  for( int i = 0; i < N; i++ ) cin >> F.at(i);
  
  sort(A.begin(), A.end());
  sort(F.rbegin(), F.rend());
  
  int ok = 1e13;
  int ng = -1;
  while( ok-ng > 1 ){
    int mid = (ok+ng)/2;
    int total = 0;
    for( int i = 0; i < N; i++ ){
      int T = A.at(i) - (mid/F.at(i));
      if( T <= 0 ) continue;
      total += T;
    }
    if( total <= K ) ok = mid;
    else ng = mid;
  }
  cout << ok << endl;
}
