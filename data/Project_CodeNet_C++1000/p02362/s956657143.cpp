#include <bits/stdc++.h>
using namespace std;

struct edge { int from, to, cost; };

typedef pair<long long, int> plli;
int main() {
  int n, m, r;
  cin>>n>>m>>r;
  vector<edge> graph(m);
  for (int i=0; i<m; i++) {
    int s, t, d;
    cin>>s>>t>>d;
    graph[i] = {s, t, d};
  }
  long long inf = 1e5 * 1e4 + 1;

  long long d[n];
  for (int i=0; i<n; i++) {
    d[i] = inf;
  }

  d[r] = 0;
  for (int i=0; i<2*n; i++) {
    for (edge e: graph) {
      if (d[e.from] != inf && d[e.to] > d[e.from] + e.cost) {
        d[e.to] = d[e.from] + e.cost;
        if (i >= n) {
          cout<<"NEGATIVE CYCLE"<<endl;
          return 0;
        }
      }
    }
  }
  for (auto di: d) {
    if (di == inf) {
      cout<<"INF"<<endl;
    } else {
      cout<<di<<endl;
    }

  }
}
