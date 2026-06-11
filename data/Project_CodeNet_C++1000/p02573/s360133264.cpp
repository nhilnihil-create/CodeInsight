#include <bits/stdc++.h>
using namespace std;

void mergeSets(vector<int>& a, int i, int j, int n) {
  if (abs(a[i]) < abs(a[j])) {
    a[j] += a[i];
    a[i] = j;
  }
  else {
    a[i] += a[j];
    a[j] = i;
  }
}

int findSet(vector<int>& a, int i, int n) {
  int j = i;
  while (a[i] > 0) {
    i = a[i];
  }
  while (a[j] > 0) {
    int t = a[j];
    a[j] = i;
    j = t;
  }
  return i;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> v(n + 1);
  for (int i = 0; i <= n; i++) {
    v[i] = -1;
  }
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    int f1 = findSet(v, a, n);
    int f2 = findSet(v, b, n);
    if (f1 != f2) {
      mergeSets(v, f1, f2, n);
    }
  }
  int ans = 0;
  for (int i = 0; i <= n; i++) {
    // cout << v[i] << " " << i << endl;
    ans = min(ans, v[i]);
  }
  ans = abs(ans);
  cout << ans << endl;
}
