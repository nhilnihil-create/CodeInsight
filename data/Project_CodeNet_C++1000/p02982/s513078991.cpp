#include <bits/stdc++.h>
using namespace std;
#define rep(i, ss, ee) for (int i = (ss); i < (ee); ++i)
using Vi = vector<int>;
using VVi = vector<Vi>;

void solve() {
  int N, D;
  cin >> N >> D;
  VVi v(N, Vi(D));
  for (auto &e1 : v)
    for (auto &e2 : e1) cin >> e2;

  int ans = 0;
  rep(i, 0, N - 1) {
    rep(j, i + 1, N) {
      int sum = 0;
      rep(k, 0, D) {
        int x = (v[i][k] - v[j][k]);
        sum += x * x;
      }
      double chk = sqrt(sum);
      if (floor(chk) == chk) ans++;
    }
  }
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
}