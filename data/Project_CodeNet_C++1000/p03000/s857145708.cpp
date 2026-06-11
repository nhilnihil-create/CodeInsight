#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, x;
  cin >> n >> x;
  int l[n];
  for (int i = 0; i < n; i++) {
    cin >> l[i];
  }

  int d = 0;
  int cnt = 1;
  for (int i = 0; i < n; i++) {
    d = d + l[i];
    if (d > x) break;
    cnt++;
  }

  cout << cnt << endl;
  return 0;
}
