#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define int long long

signed main() {
  int a,v,b,w,t;
  cin >> a >> v >> b >> w >> t;

  int dist = abs(a - b);
  int v_diff = v - w;
  if(v_diff <= 0) {
    cout << "NO" << '\n';
    return 0;
  }

  if(dist <= t * v_diff) {
    cout << "YES" << '\n';
  } else {
    cout << "NO" << '\n';
  }
}
