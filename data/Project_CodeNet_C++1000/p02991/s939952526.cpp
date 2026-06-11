#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repo(i, n) for(int i=1; i<=n; i++)
#define INF 1001001001
#define INFll 100100100100100
// debug用
#define PrintVec(x) for (auto elementPrintVec: x) { cout << elementPrintVec << " "; } cout << endl;

using namespace std;
using ull = unsigned long long;
using ll = long long;
using P = pair<int, int>;
const int mod = 1000000007;


#define MAX_V 300005

struct edge {
    int to;
    int cost;
};

// <最短距離, 頂点の番号>


int V;
vector<edge> G[MAX_V];
int d[MAX_V];

void dijkstra(int s) {
    priority_queue<P, vector<P>, greater<P> > que;
    fill(d, d+V*3, INF);
    d[s] = 0;
    que.push(P(0, s));

    while (!que.empty()) {
        P p = que.top();
        que.pop();
        int v = p.second;
        if (d[v] < p.first) continue;

        for (int i=0; i<G[v].size(); ++i) {
            edge e = G[v][i];
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}


int main(){
  int m;
  cin >> V >> m;
  rep(i, m){
    int u, v;
    cin >> u >> v;
    u--; v--;
    edge e = {v+V, 1};
    edge e2 = {v+V*2, 1};
    edge e3 = {v, 1};
    G[u].push_back(e);
    G[u+V].push_back(e2);
    G[u+2*V].push_back(e3);
  }
  int s, t;
  cin >> s >> t;
  s--; t--;
  dijkstra(s);
  if(d[t]==INF){
    cout << "-1" << endl;
  } else {
    cout << d[t]/3 << endl;
  }
  return 0;
}
