#include <bits/stdc++.h>

using namespace std;

void coloring(int cur, int par, int ex, vector<int> &res, vector<vector<pair<int, int>>> &G) {
  int nx_color = 1;
  for (auto p : G.at(cur)) {
    int nx = p.first, ind = p.second;
    if (nx == par) continue;
    while (nx_color == ex) ++nx_color;
    res.at(ind) = nx_color;
    coloring(nx, cur, nx_color++, res, G);
  }
}

int main() {
  int n;
  cin >> n;
  vector<vector<pair<int, int>>> G(n);
  for (int i=0; i<n-1; ++i) {
    int a, b;
    cin >> a >> b;
    G.at(a-1).push_back(make_pair(b-1, i));
    G.at(b-1).push_back(make_pair(a-1, i));
  }
  
  int num = -1;
  for (int i=0; i<n; ++i) if (num < (int)G.at(i).size()) num = (int)G.at(i).size();
  
  vector<int> res(n-1);
  coloring(0, -1, -1, res, G);
  cout << num << endl;
  for (int i=0; i<n-1; ++i) cout << res.at(i) << endl;
  return 0;
}
