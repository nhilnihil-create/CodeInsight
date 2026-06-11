#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
typedef long long ll;
#define REP(i, N) for (int i = 0; i < (int)N; i++)

class DAG {
  vector<bool> visited;

  void dfs(int u, vector<vector<int>> &G) {
    if(visited[u]) return;
    visited[u] = true;
    for(int v: G[u]) dfs(v, G);
    topologicalSorted.push_back(u);
  }

public:
  vector<int> topologicalSorted;
  bool valid;

  DAG(vector<vector<int>> G) {
    int V = G.size();
    visited.resize(V, false);

    for(int i = 0; i < V; i++) dfs(i, G);

    reverse(topologicalSorted.begin(), topologicalSorted.end());

    valid = static_cast<int>(topologicalSorted.size()) == V;
  }
};

int main () {
  int V, E;
  cin >> V >> E;

  vector<vector<int>> adjacentList(V, vector<int>());

  REP(i,E) {
    int s, t;
    cin >> s >> t;
    adjacentList[s].push_back(t);
  }

  DAG dag(adjacentList);
  for(auto u: dag.topologicalSorted) {
    cout << u << endl;
  }

  return 0;
}

