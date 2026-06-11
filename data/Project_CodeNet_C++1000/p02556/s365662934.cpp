#include <bits/stdc++.h>

#define nl '\n'

using namespace std;

typedef long long ll;

void solve() {
  int N;
  cin >> N;
  vector<int> x(N), y(N);
  for (int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;
    x[i] = a, y[i] = b;
  }

  int mx1 = -1e9-4, mn1 = 1e9+4;
  int mx2 = mx1, mn2 = mn1;
  for (int i = 0; i < N; i++) {
    mx1 = max(mx1, x[i] + y[i]);
    mn1 = min(mn1, x[i] + y[i]);
    mx2 = max(mx2, x[i] - y[i]);
    mn2 = min(mn2, x[i] - y[i]);
  }

  cout << max(mx1 - mn1, mx2-mn2);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  // int t;
  // cin >> t;
  // while (t--) {
  solve();
  cout << nl;
  // }

  return 0;
}