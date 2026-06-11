#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)n; i++)
#define FOR(i, m, n) for (int i = (int)m; i < (int)n; i++)

int main() {
  int N;
  cin >> N;

  vector<int> d(N);
  int sum_d = 0;

  REP(i, N) {
    cin >> d[i];
    sum_d += d[i];
  }

  int ans = 0;
  REP(i, N) ans += d[i] * (sum_d - d[i]);

  cout << ans / 2 << endl;

  return 0;
}