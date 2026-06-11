#include <bits/stdc++.h>
using namespace std;
#define rep(i, ss, ee) for (int i = (ss); i < (ee); ++i)

void solve() {
  int N;
  cin >> N;

  vector<int> x(N), y(N);
  rep(i, 0, N) cin >> x[i] >> y[i];

  vector<int> p(N);
  rep(i, 0, N) p[i] = i;

  double sum = 0;
  int cnt = 0;

  do {
    rep(i, 1, N) sum += hypot(x[p[i - 1]] - x[p[i]], y[p[i - 1]] - y[p[i]]);
    cnt++;
  } while (next_permutation(p.begin(), p.end()));

  double ans = sum / cnt;
  cout << fixed << setprecision(12) << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
}