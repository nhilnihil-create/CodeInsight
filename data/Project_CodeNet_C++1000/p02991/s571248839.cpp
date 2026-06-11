#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int> > G;
vector<int>  dist;

int main() {
    int n, m, s, t;  cin >> n >> m;
    G.resize(3*n);
    dist.resize(3*n, -1);
    for (int i = 0; i < m; i++) {
        int u, v;   cin >> u >> v;  u--, v--;
        G[u].push_back(v+n);
        G[u+n].push_back(v+2*n);
        G[u+2*n].push_back(v);
    }
    cin >> s >> t;
    queue<int> que;
    dist[s-1] = 0;
    que.push(s-1);

    while (!que.empty()) {
        int u = que.front();
        que.pop();

        for (auto v: G[u]) {
            if (dist[v] != -1)
                continue;
            
            dist[v] = dist[u] + 1;
            que.push(v);
        }
    }

    cout << ((dist[t-1] == -1) ? -1 : dist[t-1] / 3) << endl;
    return 0;
}