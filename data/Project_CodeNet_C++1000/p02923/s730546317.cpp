#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  int cur = 0, res = 0;
  for (int i = 0; i < n - 1; i++) {
    if (a[i] < a[i + 1]) {
      res = max(res, cur);
      cur = 0;
    } else {
      ++cur;
    }
  }   
  res = max(res, cur);
  cout << res << '\n';
  return 0;
}