#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define int long long

signed main() {
  int N; cin >> N;
  vector<int> A(N);
  rep(i, N) cin >> A[i];
  
  int ans = 0;
  int L = 0;
  rep(i, N) L += A[i];
  
  int m = 0;
  int M = 0;
  rep(i, N) {
    if(m < L/2) m += A[i];
    if(m == L/2) {
      cout << 0 << endl;
      return 0;
    }
    if(m > L/2) {
      M = m;
      m -= A[i];
      break;
    }
  }
  
  ans = min(abs(L-m-m), abs(L-M-M));
  
  cout << ans <<endl;
}