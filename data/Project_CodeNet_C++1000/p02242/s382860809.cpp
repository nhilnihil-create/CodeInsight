#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
using namespace std;

typedef long long ll;

#define MAX_V 100
#define INF int(1e9)

struct Edge {
    int v, cost;
    Edge() {}
    Edge(int v, int cost) : v(v), cost(cost) {}
};

// g[] : ????????????????????°???????????£??\?????????, V : ????????°, s : ?§??????¨????????????, d[] : s????????????????????????????´?????????????
int Dijkstra (vector<Edge> g[], int V, int s, int d[]) {
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > que;
    fill(d, d + V, INF);
    d[s] = 0;
    que.push(make_pair(0, s)); // pair(cost, vertex)

    while (!que.empty()) {
        pair<int, int> p = que.top();
        que.pop();
        int v = p.second, size_ = g[v].size();

        if (d[v] < p.first) continue;

        for (int i = 0; i < size_; ++i) {
            Edge e = g[v][i];
            if (d[e.v] > d[v] + e.cost) {
                d[e.v] = d[v] + e.cost;
                que.push(make_pair(d[e.v], e.v));
            }
        }
    }

}

int n, u, k, v, c, d[MAX_V + 1];
vector<Edge> g[MAX_V + 1]; // ????????°??????

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> u >> k;
        for (int j = 0; j < k; ++j) {
            cin >> v >> c;
            g[u].push_back(Edge(v, c));
        }
    }

    Dijkstra(g, n, 0, d);

    for (int i = 0; i < n; ++i) {
        cout << i << " " << d[i] << endl;
    }

    return 0;
}