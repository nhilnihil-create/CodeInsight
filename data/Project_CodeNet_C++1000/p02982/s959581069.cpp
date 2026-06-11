#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int N, D;
  cin >> N >> D;

  vector<vector<int>> x(N, vector<int>(D));
  rep(i, N) {
    rep(j, D) {
      cin >> x[i][j];
    }
  }

  int ans = 0;
  rep(i, N - 1) {
    for(int j = i + 1; j < N; ++j) {
      int d = 0;
      rep(k, D) {
        d += (x[i][k] - x[j][k]) * (x[i][k] - x[j][k]);
      }
      double dist = sqrt(d);
      if (floor(dist) == dist) {
        ans++;
      }
    }
  }

  cout << ans << endl;

  return 0;
}
