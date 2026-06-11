#include <bits/stdc++.h>
using namespace std;

const int N = 50;
int a[N], b[N], c[N], d[N], A[N];
int n, m, q, ret = 0;
 
void search(int pos, int low) {
  if (pos == n) {
    int cur = 0;
    for (int i = 0; i < q; ++i) {
      if (A[b[i]] - A[a[i]] == c[i])
        cur += d[i];
    }
    ret = max(cur, ret);
    return;
  }
  for (int i = low; i <= m; ++i) {
    A[pos] = i;
    search(pos + 1, i);
  }
}
 
int main() {
  cin >> n >> m >> q;
  for (int i = 0; i < q; ++i) {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
    --a[i]; --b[i];
  }
  search(0, 1);
  cout << ret << endl;
  return 0;
}
