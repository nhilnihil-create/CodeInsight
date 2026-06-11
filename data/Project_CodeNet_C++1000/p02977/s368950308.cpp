#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  if (__builtin_popcount(n) == 1) {
    cout << "No" << "\n";
    return 0;
  }
  auto f = [&](int i) {
    return i;
  };
  auto g = [&](int i) {
    return i + n;
  };
  auto add = [&](int i, int j) {
    cout << i << " " << j << "\n";
  };
  cout << "Yes" << "\n";
  if (n % 4 == 3) {
    for (int i = 1; i < n; ++i) {
      add(f(i), f(i + 1));
      add(g(i), g(i + 1));
    }
    add(f(n), g(1));
  } else if (n % 4 == 1) {
    for (int i = 1; i < n - 2; ++i) {
      add(f(i), f(i + 1));
      add(g(i), g(i + 1));
    }
    add(f(n - 2), g(1));
    add(f(1), f(n - 1));
    add(f(n - 1), f(n));
    add(f(1), g(n));
    add(g(n), g(n - 1));
  } else if (n % 4 == 2) {
    for (int i = 1; i < n - 3; ++i) {
      add(f(i), f(i + 1));
      add(g(i), g(i + 1));
    }
    add(f(n - 3), g(1));
    add(f(1), f(n - 2));
    add(f(n - 2), f(n - 1));
    add(f(1), g(n - 1));
    add(g(n - 1), g(n - 2));
    add(g(n - 1), f(n));
    add(f(2), g(n));
  } else {
    int m = n - 2;
    for (int i = 1; i < m - 3; ++i) {
      add(f(i), f(i + 1));
      add(g(i), g(i + 1));
    }
    add(f(m - 3), g(1));
    add(f(1), f(m - 2));
    add(f(m - 2), f(m - 1));
    add(f(1), g(m - 1));
    add(g(m - 1), g(m - 2));
    add(g(m - 1), f(m));
    add(f(2), g(m));
    add(f(n), f(n - 1));
    add(f(n - 1), f(n ^ (n - 1)));
    add(f(n ^ (n - 1)), g(n));
    add(g(n), g(n - 1));
  }
  return 0;
}
