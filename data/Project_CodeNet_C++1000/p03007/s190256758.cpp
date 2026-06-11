#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int N = 100000;

int n, a[N];
int m, x[N - 1], y[N - 1];

int main() {
  cin >> n;
  rep(i, n) cin >> a[i];
  sort(a, a + n);
  for (int i = 1; i < n - 1; i++) {
    if (a[i] < 0) {
      x[i - 1] = a[n - 1];
      y[i - 1] = a[i];
      a[n - 1] -= a[i];
    } else {
      x[i - 1] = a[0];
      y[i - 1] = a[i];
      a[0] -= a[i];
    }
  }
  x[n - 2] = a[n - 1];
  y[n - 2] = a[0];
  m = a[n - 1] - a[0];
  printf("%d\n", m);
  rep(i, n - 1) printf("%d %d\n", x[i], y[i]);
  return 0;
}