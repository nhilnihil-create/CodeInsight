#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; ++i)

using namespace std;

void solve(int N, int D, vector<vector<int>> X) {
  auto dist = [&](const vector<int>& P0, const vector<int>& P1) {
    int sum(0);
    REP(d, D)
    sum += (P0[d] - P1[d]) * (P0[d] - P1[d]);
    return sqrt(sum);
  };

  int ans(0);
  REP(j, N)
    REP(i, j) {
    double d = dist(X[i], X[j]);
    if (d - int(d) < numeric_limits<double>::epsilon())
      ans++;
  }
  cout << ans << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, D;
  cin >> N >> D;
  vector<vector<int>> X(N, vector<int>(D));
  REP(i, N)
    REP(j, D)
      cin >> X[i][j];

  solve(N, D, move(X));

  return 0;
}
