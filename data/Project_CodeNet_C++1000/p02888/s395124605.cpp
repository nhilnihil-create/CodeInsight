#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;
  
  vector<int> l(n);
  for (int i = 0; i < n; i++) cin >> l.at(i);
  
  sort(l.begin(), l.end());
  
  ll ans = 0;
  for (int i = 0; i < n - 2; i++) {
    for (int j = i + 1; j < n - 1; j++) {
      int left = j, right = n, keep = l[i] + l[j];
      while (right - left > 1) {
        int mid = (left + right) / 2;
        if (keep > l[mid]) left = mid;
        else right = mid;
      }
      ans += left - j;
    }
  }
  
  cout << ans << '\n';
}