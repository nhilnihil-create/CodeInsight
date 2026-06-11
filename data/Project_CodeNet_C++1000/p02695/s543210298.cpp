#include <bits/stdc++.h>
using namespace std;
int n, m, q, ans = 0;
int a[60], b[60], c[60], d[60];
int A[60];
void dfs(int idx) {
  if (idx > n) {
    int sum = 0;
    for (int i = 1; i <= q; i++) {
      if (A[b[i]] - A[a[i]] == c[i]) {
        sum += d[i];
      }
    }
    ans = max(ans, sum);
    return;
  }
  for (int i = A[idx - 1]; i <= m; i++) {
    A[idx] = i;
    dfs(idx + 1);
  }
}
int main() {
  cin >> n >> m >> q;
  for (int i = 1; i <= q; i++) {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
  }
  A[0] = 1;
  dfs(1);
  cout << ans << endl;
}
