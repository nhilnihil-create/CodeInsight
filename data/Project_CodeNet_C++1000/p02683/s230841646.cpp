#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
constexpr ll mod = 1e9 + 7;
#define endl '\n'
 
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
 
  ll n,m,X;
  cin >> n >> m >> X;
  vector<vector<ll>> A(n, vector<ll>(m));
  vector<ll> C(n);
  for (int i = 0; i < n; ++i) {
    cin >> C[i];
    for (auto& _b : A[i]) cin >> _b;
  }
  ll ans = INT_MAX;
  vector<ll> cur(m);
  for (int state = 0; state < (1 << n); ++state) {
    int v = state;
    ll cost = 0;
    fill(cur.begin(), cur.end(), 0);

    while (v) {
      int i = ffs(v)-1;
      for (int j = 0; j < m; ++j) cur[j] += A[i][j];
      cost += C[i];
      v &= v-1;
    }
    if (cost >= ans) continue;
    bool good = true;
    for (int j = 0; j < m; ++j) {
      if (cur[j] < X) {
        good = false;
        break;
      }
    }
    if (good) {
      ans = cost;
    }
  }
  if (ans == INT_MAX) ans = -1;
  cout << ans << endl;
}
