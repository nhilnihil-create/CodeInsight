#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  int sum = 0;
  for (auto&& e : a) {
    cin >> e;
    sum += e;
  }
  sort(a.begin(), a.end(), greater<int>());
  bool ok = a[m - 1] >= (sum + 4 * m - 1) / (4 * m);
  cerr << a[m - 1] << ' ' << 1 / (4 * m) * sum << endl;
  cout << (ok ? "Yes" : "No") << '\n';
  return 0;
}
