#include <iostream>

using namespace std;

const int kMaxN = 100001;

int a[kMaxN];
int n, m, x, y, c;

int R(int x) {
  return a[x] == x ? x : a[x] = R(a[x]);
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    a[i] = i;
  }
  for (int i = 1; i <= m; i++) {
    cin >> x >> y;
    if (R(x) != R(y)) {
      c++;
      a[R(x)] = R(y);
    }
  }
  cout << n - 1 - c;
  return 0;
}