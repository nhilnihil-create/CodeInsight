#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  int n;
  cin >> n;
  vector < int > a(n), b (n);
  for (auto &i : a) cin >> i;
  for (auto &i : b) cin >> i;
  ll moves = 0;
  priority_queue < pair < int, int > > q;
  for (int i = 0; i < n; i++) q.push ({b[i], i});

  while (!q.empty()) {
    int u = q.top().second;
    q.pop();
    int l = u - 1, r = u + 1;
    if (l < 0) l = n - 1;
    if (r == n) r = 0;

    int k = (b[u] - a[u]) / (b[l] + b[r]);
    if (b[u] != a[u] && k <= 0) {
      cout << -1 << '\n';
      return 0;
    }
    b[u] -= k * (b[l] + b[r]);
    moves += k;

    if (b[u] != a[u]) q.push ({b[u], u});
  }

  cout << moves << '\n';
}
