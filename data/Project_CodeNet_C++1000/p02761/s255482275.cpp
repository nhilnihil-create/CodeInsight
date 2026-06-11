#include <bits/stdc++.h>
using namespace std;

template<typename T> void drop(const T &x){cout<<x<<'\n';exit(0);}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> x(n,-1);
  for(int i=0; i<m; ++i) {
    int s, c;
    cin >> s >> c;
    if(x[s-1] == -1 || x[s-1] == c) {
      x[s-1] = c;
    } else {
      cout << -1 << '\n'; return;
    }
  }

  if(n != 1 && x[0] == 0) {
    cout << -1 << '\n'; return;
  }

  for(int i=1; i<n; ++i) {
    if(x[i] == -1) x[i] = 0;
  }
  if(x[0] == -1 && n > 1) x[0] = 1; 
  else if(x[0] == -1) x[0] = 0;
  
  for(int i=0; i<n; ++i) cout << x[i];
  cout << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T=1;
  //cin >> T;
  while(T--) solve();

  return 0;
}
