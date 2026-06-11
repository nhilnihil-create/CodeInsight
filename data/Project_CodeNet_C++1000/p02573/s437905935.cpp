#include <bits/stdc++.h>
using namespace std;

int findSet(vector<int>& a, int i) {
  if (a[i] < 0) return i;
  return a[i] = findSet(a, a[i]);
}

void mergeSets(vector<int>& a, int i, int j) {
  int x = findSet(a, i);
  int y = findSet(a, j);
  if (x == y) {
    return;
  }
  if (a[x] > a[y]) {
    int t = x;
    x = y;
    y = t;
  }
	a[x] += a[y];
	a[y] = x;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    v[i] = -1;
  }
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    mergeSets(v, a, b);
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    // cout << v[i] << " " << i << endl;
    ans = min(ans, v[i]);
  }
  ans = abs(ans);
  cout << ans << endl;
}