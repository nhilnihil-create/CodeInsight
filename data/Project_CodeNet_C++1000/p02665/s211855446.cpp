#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MN = 100005;
unsigned long long s = 0;
ll n, a[MN];
ll max_p[MN];

int main() {
  cin >> n;
  for (int i = 0; i <= n; ++i) {
    cin >> a[i];
    s += a[i];
  }
  if (a[0] > 0) {
    if (n == 0 && a[0] < 2) {
      cout << a[0] << endl;
    } else {
      cout << -1 << endl;
    }
    return 0;
  }

  max_p[0] = 1;
  for (int i = 1; i < n; ++i) {
    max_p[i] = min((ll)s + 1, max_p[i - 1] * 2 - a[i]);
  }
  max_p[n] = 0;

  for (int i = n - 1; i >= 0; --i) {
    if (max_p[i] < 1 || max_p[i] * 2 < max_p[i + 1] + a[i + 1]) {
      cout << -1 << endl;
      return 0;
    }
    max_p[i] = min(max_p[i], max_p[i + 1] + a[i + 1]);
    s += max_p[i];
  }
  cout << s << endl;
}