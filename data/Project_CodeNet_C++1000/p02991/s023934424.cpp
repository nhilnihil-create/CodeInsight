#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> P;

const int INF = 330000;
int n, m, s, t;
vector<int> edge[330000];
bool done[330000];

int bfs(int u) {
  queue<P> q;
  
  q.push(P(u, 0));
  
  while (q.size()) {
    P p = q.front();
    q.pop();
    u = p.first;
    int dist = p.second;
    for (int v: edge[u]) {
      if (v == t) return (dist + 1) / 3;
      if (done[v]) continue;
      q.push(P(v, dist + 1));
      done[v] = true;
    }
  }
  
  return -1;
}

int main() {
  cin >> n >> m;
  
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    edge[u].push_back(v+n);
    edge[u+n].push_back(v+2*n);
    edge[u+2*n].push_back(v);
  }
  
  cin >> s >> t;
  s--;
  t--;
  
  cout << bfs(s) << endl;
  return 0;
}
