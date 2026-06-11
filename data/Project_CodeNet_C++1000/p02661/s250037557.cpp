#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for(int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  int l = a[n/2] + (n % 2 ? 0 : a[n/2 - 1]);
  int r = b[n/2] + (n % 2 ? 0 : b[n/2 - 1]);
  cout << r - l + 1 << '\n';
}