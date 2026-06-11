#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<pair<int, int>> xy(n);
  for (int i = 0; i < n; ++i)
    cin >> xy[i].first >> xy[i].second;

  map<pair<int, int>, int> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == j)
        continue;
      int x = xy[i].first - xy[j].first;
      int y = xy[i].second - xy[j].second;
      auto p = make_pair(x, y);
      if (m.find(p) == m.end())
        m.emplace(p, 0);
      m[p]++;
    }
  }

  int cnt = 0;
  for (auto p : m)
    cnt = max(cnt, p.second);

  int cost = n - cnt;
  cout << cost << endl;
}