#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define REP(i, n) for ( int i = 0; i < (n); i++ )
 
signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int N;
  cin >> N;

  int sum = 0;
  vector<int> A(N);
  REP(i, N) {
    cin >> A[i];
    sum += A[i];
  }

  int ans = 1e10;
  int now = 0;
  REP(i, N) {
    now += A[i];
    // cout << now-(sum-now) << endl;
    if ( (double)now <= (double)sum/2 ) ans = min({ans, abs(sum-2*now)});
    if ( (double)now >= (double)sum/2 ) ans = min({ans, abs(now-(sum-now))});    
  }

  cout << ans << endl;
  
  return 0;
}
