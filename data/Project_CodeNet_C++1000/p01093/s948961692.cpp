#include <bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define DEBUG(x) cerr << #x << " = " << x << endl

signed main() {
  ios::sync_with_stdio(false);
  while(true) {
    int N; cin >> N;
    if(N == 0) break;
    vector<int> A(N);
    REP(i,N) cin >> A[i];
    int ans = abs(A[1] - A[0]);
    REP(i,N) {
      for(int j = i + 1; j < N; ++j) {
        ans = min(ans, abs(A[i] - A[j]));
      }
    }
    cout << ans << endl;
  }
}