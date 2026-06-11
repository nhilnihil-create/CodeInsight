#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  vector<vector<int>> v(100001);
  rep(i, 0, n) {
    int a, b;
    cin >> a >> b;
    v[a].push_back(b);
  }

  priority_queue<int> pq;
  ll ans = 0;
  rep(i, 1, m + 1) {
    rep(j, 0, v[i].size()) pq.push(v[i][j]);
    if (pq.empty())
      continue;
    ans += pq.top();
    pq.pop();
  }

  cout << ans << endl;
}
