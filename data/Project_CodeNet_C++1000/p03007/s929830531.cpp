#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;
  
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a.at(i);
  
  sort(a.begin(), a.end());
  
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (i == 0) ans -= a.at(i);
    else if (i == n - 1) ans += a.at(i);
    else ans += abs(a.at(i));
  }
  
  cout << ans << '\n';
  
  int keep = a.front(), keep2 = a.back();
  for (int i = 1; i < n - 1; i++) {
    if (a.at(i) >= 0) {
      cout << keep << " " << a.at(i) << '\n';
      keep -= a.at(i);
    }
    else {
      cout << keep2 << " " << a.at(i) << '\n';
      keep2 -= a.at(i);
    }
  }
  cout << keep2 << " " << keep << '\n';
}