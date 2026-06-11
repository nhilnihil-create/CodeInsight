#include <bits/stdc++.h>
using namespace std;

int N, mx;
vector<vector<pair<int, int>>> G;
vector<int> ans;

void dfs(int v, int pv, int c) {
  for (auto g : G.at(v)) {
    if (g.first == pv) continue;
    ans.at(g.second) = c++ % mx + 1;
    dfs(g.first, v, c);
  }
}

int main() {
  cin >> N;
  G.resize(N);
  ans.resize(N - 1);
  for (int i = 0, a, b; cin >> a >> b; i++)
    G.at(--a).push_back({--b, i}), G.at(b).push_back({a, i});
  for (auto g : G) mx = max(mx, (int) g.size());
  dfs(0, -1, 0);
  cout << mx << "\n";
  for (auto a : ans) cout << a << "\n";
}