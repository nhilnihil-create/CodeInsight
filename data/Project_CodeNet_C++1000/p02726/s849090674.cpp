#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;
template <class T>
using V = vector<T>;

int main() {
  int n, x, y;
  cin >> n >> x >> y;

  V<int> ans(n);
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++) {
      int c = j - i;
      int fi = min(abs(x - i), abs(y - i));
      int fj = min(abs(y - j), abs(y - j));
      c = min(c, fi + fj + 1);
      ans[c]++;
    }

  for (int k = 1; k < n; k++) {
    printf("%d\n", ans[k]);
  }
}
