#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int N = 1e5 + 5;
vector<int> g[N];
int dist[N][3];

int bfs(int source, int target) {
    for (int i = 0; i < N; i++) for (int j = 0; j < 3; j++) dist[i][j] = 1e8;
    queue<pair<int, int> > q;
    q.push({source, 0});
    dist[source][0] = 0;
    while (q.size()) {
        int node = q.front().first;
        int mod = q.front().second;
        q.pop();
        for (auto child:g[node]) {
            int nmod = (mod + 1) % 3;
            if (dist[child][nmod] > dist[node][mod] + 1) {
                dist[child][nmod] = dist[node][mod] + 1;
                q.push({child, nmod});
            }
        }
    }
    if (dist[target][0] > 1e7) return -1;
    return dist[target][0] / 3;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
     }
    int s, t;
    cin >> s >> t;
    cout << bfs(s, t) << endl;
    return 0;
}
