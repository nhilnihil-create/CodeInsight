#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <math.h>
#include <sstream>
#include <numeric>
#include <string>
#include <cassert>
#include <bitset>

using namespace std;
typedef long long ll;

vector<vector<pair<int,int> > > g;
vector<int> edge_colors;

void dfs(int u, int p, int c) {
  int color = 0;
  for (auto e : g[u]) {
    int v = e.first;  int edge_id = e.second;
    if (v == p) continue;
    if (color == c) ++color;
    edge_colors[edge_id] = color;
    dfs(v, u, color);
    ++color;
  }
}

int main() {
  int N;
  cin >> N;
  
  g = vector<vector<pair<int, int> > > (N);
  edge_colors = vector<int>(N - 1, -1);
  
  for (int i = 0; i < N - 1; ++i) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    g[a].push_back(make_pair(b, i));
    g[b].push_back(make_pair(a, i));
  }

  int mx_deg = 0;
  for (int u = 0; u < N; ++u) {
    int deg = g[u].size();
    mx_deg = max(mx_deg, deg);
  }
  int K = mx_deg;

  dfs(0, -1, -1);

  cout << K << endl;
  for (int i = 0; i < N - 1; ++i) {
    cout << edge_colors[i] + 1 << endl;
  }
  
  return 0;
}
