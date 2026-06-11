#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
signed main() { 
  ios::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  vector<long long> leaf(n + 1);
  for (int i = 0; i <= n; i++) {
    cin >> leaf[i];
  }
  vector<long long> max_node(n + 1), min_node(n + 1);
  if (leaf[0] > 1) {
    cout << -1 << endl;
    return 0;
  }
  max_node[0] = 1 - leaf[0];
  min_node[0] = 1 - leaf[0];
  cerr << 0 << " " << max_node[0] << " " << min_node[0] << endl;
  for (int i = 1; i <= n; i++) {
    long long mx = min((long long) 1e18, max_node[i - 1] * 2);
    long long mi = min((long long) 1e18, min_node[i - 1]);
    if (leaf[i] > mx) {
      cout << -1 << endl;
      return 0;
    }
    max_node[i] = mx - leaf[i];
    min_node[i] = max(0LL, mi - leaf[i]);
    //cerr << i << " " << max_node[i] << " " << min_node[i] << endl;
  }
  vector<long long> non_leaf(n + 1);
  non_leaf[n] = 0;
  for (int i = n - 1; i >= 0; i--) {
    long long need = non_leaf[i + 1] + leaf[i + 1];
    if ((need + 1) / 2 > max_node[i] || min_node[i] > need) {
      cout << -1 << endl;
      return 0;
    }
    non_leaf[i] = min(max_node[i], need);
  }
  long long ans = 0;
  for (int i = 0; i <= n; i++) {
    ans += non_leaf[i] + leaf[i];
  }
  cout << ans << endl;
  return 0;
}