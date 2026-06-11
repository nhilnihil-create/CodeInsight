#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
const ll INF = LONG_LONG_MAX / 2;
const ll mod = 1000000000 + 7;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  int N, Q;
  cin >> N >> Q;
  dsu d(N);
  for (int i = 0; i < Q; i++) {
    int t, u, v;
    cin >> t >> u >> v;
    if (t == 0) {
      d.merge(u, v);
    } else if (t == 1) {
      if (d.same(u, v))
        cout << "1" << endl;
      else
        cout << "0" << endl;
    }
  }
}
