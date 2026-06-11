/*
  In the name of ALLAH
  Author : Raashid Anwar
*/
 
#include <bits/stdc++.h>
using namespace std;
 
#define int int64_t
const int M1 =  998244353;
const int M2 =  1000000007;
mt19937 rng((uint64_t)chrono::steady_clock::now().time_since_epoch().count());

void solve() {
  int n;
  cin >> n;
  set <int> mp[2][2];
  int ans = 0;
  for(int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    for(int l : {0, 1})
        for(int m : {0, 1})
          if(!mp[l][m].empty()) {
            int sum = (l? -x: x) + (m? -y: y);
            ans = max(ans, sum + *mp[l][m].rbegin());
          }
    for(int l : {0, 1})
      for(int m : {0, 1})
        mp[l][m].insert({(l? x: -x) + (m? y: -y)});
  }
  cout << ans << "\n";
}
 
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
}