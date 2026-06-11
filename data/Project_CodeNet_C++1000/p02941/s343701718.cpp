#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) cin >> b[i];
  set<pair<int, int>> s;
  vector<bool> ok(n);
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] == b[i]) {
      ok[i] = true;
      cnt++;
    } else {
      s.insert(make_pair(b[i], i));
    }
  }
  constexpr int kInf = 2'000'000'000;
  int64_t ans = 0;
  while (cnt < n) {
    int x = s.rbegin()->second;
    s.erase(make_pair(b[x], x));
    int y = (x + n - 1) % n, z = (x + 1) % n;
    // cout << "y = " << y << " z = " << z << endl;
    if (b[y] + b[z] > b[x] - a[x]) {
      cout << -1 << "\n";
      return 0;
    }
    // cout << "x = " << x << " b[x] = " << b[x] << " b[y] = " << b[y] << " b[z] = " << b[z] << endl;
    int sum = b[y] + b[z];
    if (ok[y] && ok[z]) {
      if ((b[x] - a[x]) % sum != 0) {
        cout << -1 << "\n";
        return 0;
      }
      ans += (b[x] - a[x]) / sum;
      b[x] = a[x];
      ok[x] = true;
      cnt++;
    } else {
      int obj = b[x] - (max(ok[y] ? -kInf : b[y], ok[z] ? -kInf : b[z]) - 1);
      int k = (obj + sum - 1) / sum;
      // cout << "obj = " << obj << " k = " << k << endl;
      ans += k;
      b[x] -= sum * k;
      // cout << "become b[x] = " << b[x] << endl;
      if (b[x] < a[x]) {
        cout << -1 << "\n";
        return 0;
      }
      // assert(b[x] < (ok[y] ? kInf : b[y]) && b[x] < (ok[z] ? kInf : b[z]));
      if (b[x] == a[x]) {
        ok[x] = true;
        cnt++;
      } else {
        s.insert(make_pair(b[x], x));
      }
    }
  }
  cout << ans << "\n";
  return 0;
}
