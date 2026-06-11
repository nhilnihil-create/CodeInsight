#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
int ans[555][555];
void doit(int l, int r, int level) {
  if (l + 1 == r) return;
  int mid = (l + r) / 2;
  for (int i = l; i < mid; i++) {
    for (int j = mid; j < r; j++) {
      ans[i][j] = level;
    }
  }
  doit(l, mid, level + 1);
  doit(mid, r, level + 1);
}
signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  doit(0, n, 1);
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (j > i + 1) cout << " ";
      cout << ans[i][j];
    }
    cout << '\n';
  }
  return 0;
}