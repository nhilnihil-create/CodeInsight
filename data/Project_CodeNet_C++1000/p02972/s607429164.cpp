#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  vector<int> b(n), c;
  for (int i = n - 1; i >= 0; i--) {
    int tmp = 0;
    for (int j = i; j < n; j += (i + 1)) tmp += b[j];
    if (tmp % 2 != a[i]) {
      b[i] = 1;
      c.push_back(i + 1);
    }
  }

  cout << c.size() << endl;
  rep(i, c.size()) printf("%d%c", c[i], (i == c.size() - 1 ? '\n' : ' '));
  return 0;
}
