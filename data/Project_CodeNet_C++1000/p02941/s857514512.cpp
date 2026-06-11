#include <bits/stdc++.h>
using namespace std;

const int N = 200000;

int n;
int a[N + 5], b[N + 5];

#define lst(x) (x == 1 ? n : x - 1)
#define nxt(x) (x == n ? 1 : x + 1)

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);
  for (int i = 1; i <= n; ++i) scanf("%d", b + i);

  long long ans = 0;
  for (bool flag = 1; flag; ) {
    flag = false;
    for (int i = 1; i <= n; ++i) if (b[i] > a[i] && b[i] - a[i] >= b[lst(i)] + b[nxt(i)]) {
      flag = true;
      ans += (b[i] - a[i]) / (b[lst(i)] + b[nxt(i)]);
      b[i] = (b[i] - a[i]) % (b[lst(i)] + b[nxt(i)]) + a[i];
    }
  }

  for (int i = 1; i <= n; ++i) {
    if (a[i] != b[i]) {
      printf("-1\n");
      return 0;
    }
  }
  printf("%lld\n", ans);

  return 0;
}
