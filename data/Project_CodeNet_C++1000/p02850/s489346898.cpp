#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define reps(i,a,b) for(int i= a; i < b; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int n;
vector<bool> seen;
vector<vector<int>> graph;
map<pair<int, int>, int> color;
int deg = 0;

void dfs(int v,  int pv, int pc) {
  seen.at(v) = true;
  int nc = 1;

  for (auto &nv: graph.at(v)) {
    if (seen.at(nv)) continue;
    if (nc == pc) nc++;
    pair<int, int> p = make_pair(min(v, nv), max(v, nv));
    color[p] = nc;
    dfs(nv, v, nc);
    nc++;
  }
  deg = max(deg, (int)graph.at(v).size());
}

int main()
{ 
  cin >> n;
  seen.resize(n, false);
  graph.resize(n, vector<int>());
  vector<pair<int, int>> edges(n-1);
  rep(i, n-1) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    graph.at(a).push_back(b);
    graph.at(b).push_back(a);
    edges.at(i) = make_pair(a, b);
  }
  dfs(0, -1, -1);
  cout << deg << endl;
  for (auto &v : edges) {
    cout << color.at(v) << endl;
  }
  
  return 0;
}