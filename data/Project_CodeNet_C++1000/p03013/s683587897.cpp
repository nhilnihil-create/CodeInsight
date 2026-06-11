#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n, m;
  cin >> n >> m;
  vector<int> rs(n, 0);
  vector<int> as(m);
  for (int &a : as) cin >> a;
  const int MOD = 1000000007;

  for (const int &a : as) {
    rs[a - 1] = -1;
  }

  for (int i = 0; i < n; i++) {
    if (rs[i] == -1) {
      rs[i] = 0;
    } else {
      if (i == 0) {
        rs[0] = 1;
      } else if (i == 1) {
        rs[1] = rs[0] + 1;
      } else {
        rs[i] = rs[i - 1] + rs[i - 2];
        if (rs[i] > MOD) rs[i] -= MOD;
      }
    }
  }

  cout << rs[n - 1] << endl;
  return 0;
}