#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cout << fixed << setprecision(10);
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  priority_queue<double, vector<double>, greater<double>> que;
  for (int i = 0; i < n; ++i) {
    int v;
    cin >> v;
    que.emplace(v);
  }

  while (que.size() != 1) {
    auto p = que.top(); que.pop();
    auto q = que.top(); que.pop();

    que.emplace((p + q) / 2.0);
  }

  cout << que.top() << '\n';
  que.pop();

  return (0);
}
