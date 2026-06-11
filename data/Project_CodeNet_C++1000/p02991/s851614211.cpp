#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> P;

const int INF = 330000;
int n, m, s, t, ans;
vector<int> edge[330000];
int dist[330000];


void dijkstra(int u) {
  priority_queue<P, vector<P>, greater<P> > pq;
  
  for (int i = 0; i < n * 3; i++) {
    dist[i] = INF;
  }
  
  dist[u] = 0;
  pq.push(P(0, u));
  
  while (pq.size()) {
    P p = pq.top();
    pq.pop();
    u = p.second;
    if (dist[u] < p.first) continue;
    for (int v: edge[u]) {
      if (dist[v] > dist[u] + 1) {
        dist[v] = dist[u] + 1;
        pq.push(P(dist[v], v));
      }
    }
  }
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
  
  dijkstra(s);
  
  if (dist[t] == INF) {
    ans = -1;
  } else {
    ans = dist[t] / 3;
  }
  
  cout << ans << endl;
  return 0;
}
