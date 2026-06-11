#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int main() {
  int n;
  cin >> n;
  int x[n];
  int h = 0, l = 10000;
  for (int i = 0 ; i < n; i++) {
    cin >> x[i];
    l = min(l, x[i]);
    h = max(h, x[i]);
  }
  long long res = INT_MAX;
  for (int p = l ; p <= h; p++) {
    long long pt = 0;
    for (int j = 0; j < n; j++) {
      pt += (x[j] - p) * (x[j] - p);
    }
    res = min(res, pt);
  }
  cout << res << endl;
  return 0;
}

