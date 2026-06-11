#include <bits/stdc++.h>
using namespace std;

int N, mx;
vector<vector<pair<int, int>>> G;
vector<int> ans;

void dfs(int v, int pv, int c) {
  for (auto g : G.at(v)) {
    if (g.first == pv) continue;
    int nc = c % mx + 1; c++;
    ans.at(g.second) = nc;
    dfs(g.first, v, nc);
  }
}

int main() {
  cin >> N;
  G.resize(N);
  ans.resize(N - 1);
  for (int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    G.at(--a).push_back({--b, i});
    G.at(b).push_back({a, i});
  }
  for (auto g : G) mx = max(mx, (int) g.size());
  cout << mx << "\n";
  dfs(0, -1, 0);
  for (auto a : ans) cout << a << "\n";
}