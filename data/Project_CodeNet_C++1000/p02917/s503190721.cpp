#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n - 1);
  for (int i = 0; i < n - 1; i++)
    cin >> a[i];
  vector<int> res(n);
  res[0] = a[0];
  for (int i = 1; i < n - 1; i++) {
    res[i] = a[i];
    if (res[i] > a[i - 1])
      res[i] = a[i - 1]; 
  }
  res[n - 1] = a[n - 2];
  int ans = accumulate(res.begin(), res.end(), 0);
  cout << ans << '\n';
  return 0;
}