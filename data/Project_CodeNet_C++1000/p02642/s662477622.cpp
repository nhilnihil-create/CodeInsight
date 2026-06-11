#include <bits/stdc++.h>
using namespace std;

#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)
#define rep(i, n) repi(i, 0, n)
#define all(x) (x).begin(), (x).end()

inline void Main() {
  int n; cin >> n;
  vector<int> a(n), b;
  rep(i, n) cin >> a[i];
  sort(all(a));
  rep(i, n) {
    repi(j, 1, a[n-1] / a[i] + 1) {
      // cout << a[i] * j << endl;
      b.push_back(a[i] * j);
    }
  }
  sort(all(b));
  int r = 0;
  rep(i, n) {
    int x = upper_bound(all(b), a[i]) - lower_bound(all(b), a[i]);
    if (x >= 2) {
      // cout << i << endl;
      r++;
    }
  }
  cout << n - r << endl;
}

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(20);
  Main();
  return 0;
}
