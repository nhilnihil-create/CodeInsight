#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1000000007;
long long MOD = 1e9 + 7;

int main() {
  int n, k;
  cin >> n >> k;
  int ma = (n - 1) * (n - 2) / 2;
  if (ma < k)
    cout << -1 << endl;
  else {
    vector<P> res;
    for (int i = 1; i <= n - 1; i++) res.push_back({i, n});
    int ci = 1, cj = 2;
    for (int w = 0; w < ma - k; ++w) {
      res.push_back({ci, cj});
      ++cj;
      if (cj == n) {
        ++ci;
        cj = ci + 1;
      }
    }
    cout << res.size() << endl;
    for (auto p : res) cout << p.first << " " << p.second << endl;
  }
}
