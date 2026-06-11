#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, n;
  cin >> x >> n;
  
  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p.at(i);
  }
  
  sort(p.begin(), p.end());
  int ma = x;
  for (int i : p) {
    if (ma == i) ma++;
    else if (ma > x) break;
  }
  if (ma == x) {
    cout << ma << endl;
    return 0;
  }
  
  reverse(p.begin(), p.end());
  int mi = x;
  for (int i : p) {
    if (mi == i) mi--;
    else if (mi < x) break;
  }
  
  int ans = 0;
  if (x - mi <= ma - x) {
    ans += mi;
  }
  if (x - mi > ma - x) {
    ans += ma;
  }
  
  cout << ans << endl;
  return 0;
}