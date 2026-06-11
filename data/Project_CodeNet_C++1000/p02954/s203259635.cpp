#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define REP(i, n) for ( int i = 0; i < (n); i++ )
 
signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  string s;
  cin >> s;

  vector<int> ans(s.size(), 0);  
  int lr = 0, rr = 0, ll = 0, rl = 0;
  int now = 0;  
  for ( int i = 1; i < (int)s.size(); i++ ) {
    // cout << now << " " << lr << " " << rr << " " << ll << " " << rl << endl;    
    if ( now == 0 ) {
      if ( s[i] == 'R' ) {
	rr = i;
      } else {
	now = 1;
	ll = rl = i;	
      }
    } else {
      if ( s[i] == 'R' ) {
	ans[rr] = (rr - lr)/2 + (rl - rr)/2 + 1;	
	ans[ll] = (ll - lr)/2 + (rl - ll)/2 + 1;	
	lr = rr = ll = rl = i;
	now = 0;
      } else {
	rl = i;	
      }
    }
    // cout << now << " " << lr << " " << rr << " " << ll << " " << rl << endl;    
  }

  ans[rr] = (rr - lr)/2 + (rl - rr)/2 + 1;	
  ans[ll] = (ll - lr)/2 + (rl - ll)/2 + 1;

  REP(i, (int)s.size()) {
    if ( i ) cout << " ";
    cout << ans[i];
  } cout << endl;

  return 0;
}
