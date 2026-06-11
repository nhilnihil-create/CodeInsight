#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  int n; cin >> n;
  vector<int> a(n);
  int ans = 1e9;
  for(int i = 0; i < n; i++) cin >> a[i];
  for(int t = 1; t < n; t++){
    int x = 0, y = 0;
    for(int i = 0; i < n; i++){
      if(i + 1 <= t) x += a[i];
      else y += a[i];
    }
    ans = min(ans, abs(x - y));
  }
  cout << ans << endl;
}