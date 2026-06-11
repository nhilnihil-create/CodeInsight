#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;
template <class T>
using V = vector<T>;

int count_one(ll n) {
  bitset<64> b = n;
  return b.count();
}

int main() {
  int n;
  cin >> n;
  V<V<int>> x(n), y(n);
  rep(i, n) {
    int num;
    cin >> num;
    x[i].resize(num);
    y[i].resize(num);
    rep(j, num) cin >> x[i][j] >> y[i][j];
  }

  int ans = 0;
  rep(i, 1 << n) {
    bool ok = true;
    V<int> p(n);
    rep(j, n) p[j] = (i & 1 << j) ? 1 : 0;
    rep(j, n) {
      if ((i & 1 << j) == 0) continue;
      int num = x[j].size();
      for (int k = 0; k < num; k++) {
        int no = x[j][k] - 1;
        if (p[no] != y[j][k]) ok = false;
      }
    }
    if (ok) ans = max(ans, count_one(i));
  }
  cout << ans << endl;
}
