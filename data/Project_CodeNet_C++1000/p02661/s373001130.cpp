#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
signed main() { 
  ios::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cin >> b[i];
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  int d = b[n / 2] + b[(n - 1) / 2] - a[n / 2] - a[(n - 1) / 2];
  if (n % 2) d /= 2;
  cout << d + 1 << endl;
  return 0;
}
