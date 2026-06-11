#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int n, k;

int main() {
  cin >> n >> k;
  if ((n - 1) * (n - 2) / 2 < k) {
    cout << -1 << endl;
    return 0;
  }
  int m = 0;
  vector<int> u, v;
  for (int i = 2; i <= n; i++) {
    u.push_back(1);
    v.push_back(i);
    m++;
  }
  int rst = (n - 1) * (n - 2) / 2 - k;
  int x = 2;
  while (rst > 0) {
    for (int y = x + 1; y <= n; y++) {
      u.push_back(x);
      v.push_back(y);
      m++;
      if (--rst == 0) break;
    }
    x++;
  }
  cout << m << endl;
  rep(i, m) printf("%d %d\n", u[i], v[i]);
  return 0;
}