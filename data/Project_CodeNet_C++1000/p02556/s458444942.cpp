#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;
using P = pair<ll, int>;

int main() {
  int n;
  cin >> n;
  vector<int> xs(n), ys(n);
  vector<int> zs(n), ws(n);
  rep(i, n) {
    cin >> xs[i] >> ys[i];
    zs[i] = xs[i] + ys[i];
    ws[i] = xs[i] - ys[i];
  }
  sort(zs.begin(), zs.end());
  sort(ws.begin(), ws.end());
  cout << max(zs[n - 1] - zs[0], ws[n - 1] - ws[0]) << endl;
  return 0;
}
