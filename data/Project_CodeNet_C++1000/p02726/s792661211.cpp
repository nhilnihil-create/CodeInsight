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


#define INF 1e+9
#define MAX_V 2005

struct edge {
    int to;
    int cost;
};

// <最短距離, 頂点の番号>
using P = pair<int, int>;

int V;
vector<edge> G[MAX_V];
int d[MAX_V];

void dijkstra(int s) {
    priority_queue<P, vector<P>, greater<P> > que;
    fill(d, d+V, INF);
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

int main() {
    cin >> V;
    int x, y;
    cin >> x >> y;
    x--; y--;
    edge e3 = {y, 1};
    edge e4 = {x, 1};
    G[x].push_back(e3);
    G[y].push_back(e4);
    for (int i=0; i<V-1; ++i) {
        //有向グラフ
        edge e = {i+1, 1};
        edge e2 = {i, 1};
        G[i].push_back(e);
        G[i+1].push_back(e2);
    }
    vector<int> ans(V);
    rep(i, V){
      dijkstra(i);
      for(int j=i+1; j<V; j++){
        ans[d[j]]++;
      }
    }
    for (int i=1; i<V; ++i) {

            cout << ans[i] << endl;
    }
}
