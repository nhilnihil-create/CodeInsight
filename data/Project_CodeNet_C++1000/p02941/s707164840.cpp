#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];

  priority_queue<P> pq;
  for (int i = 0; i < n; i++) {
    if (a[i] != b[i]) pq.push({b[i], i});
  }
  ll ans = 0LL;
  while (!pq.empty()) {
    int p = pq.top().second;
    pq.pop();
    int l = (p + n - 1) % n;
    int r = (p + 1) % n;
    int s = b[l] + b[r];
    if (b[p] - a[p] < s) {
      cout << -1 << endl;
      return 0;
    }
    int c = (b[p] - a[p]) / s;
    b[p] -= c * s;
    ans += c;
    if (b[p] <= a[p]) continue;
    pq.push({b[p], p});
  }
  cout << ans << endl;
}
