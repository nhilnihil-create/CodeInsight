#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define REP(i, n) for ( int i = 0; i < (n); i++ )
 
signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int N;
  cin >> N;

  if ( N%2 ) {
    cout << 0 << endl;
    return 0;
  }

  int now = 5;
  int ans = 0;  
  while ( now <= N ) {
    ans += N/(now*2);    
    now *= 5;    
  }

  cout << ans << endl;  

  return 0;
}
