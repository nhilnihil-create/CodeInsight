#include <bits/stdc++.h>

using namespace std;

typedef long long llint;

int main() {
  int n;
  cin >> n;
  vector<llint> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  llint cur = 1000;
  for (int i = 0; i + 1 < n; i++) {
    llint cnt = 0;
    if (a[i] < a[i + 1]) cnt = cur / a[i];
    cur += (a[i + 1] - a[i]) * cnt;
  }
  cout << cur << endl;

  return 0;
}