#include <bits/stdc++.h>
using namespace std;

int n, k, a[200005];

bool ok(int c) {
  int cnt = 0;
  for (int i = 0; i < n; i++) cnt += a[i] / c;
  return cnt <= k;
}

int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
  }
  int l = 0, r = 1001001001;
  while (r - l > 1) {
    int c = (l + r) / 2;
    (ok(c) ? r : l) = c;
  }
  cout << r << endl;
  return 0;
}