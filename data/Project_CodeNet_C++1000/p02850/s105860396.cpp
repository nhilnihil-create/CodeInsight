#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>
#include <sstream>
#include <fstream>
#include <climits>
#include <map>
#include <numeric>
#include <functional>
#include <utility>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef long long ll;

struct Edge {
  int to, id;
};

vector<vector<Edge> > g;
vector<int> ans;

void dfs(int node, int p = -1, int e = -1) {
  int k = 1;
  rep(i, g[node].size()) {
    if (g[node][i].to == p) continue;
    if (k == e) k++;
    ans[g[node][i].id] = k++;
    dfs(g[node][i].to, node, k - 1);
  }
}

int main(void) {
  int n;
  cin >> n;
  g.resize(n);
  rep(i, n - 1) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    g[a].push_back(Edge{ b, i });
    g[b].push_back(Edge{ a, i });
  }
  ans.resize(n - 1);

  dfs(0);

  int mx = 0;
  rep(i, n) mx = max(mx, (int)g[i].size());
  cout << mx << endl;
  rep(i, n - 1) {
    cout << ans[i] << endl;
  }
  return 0;
}
