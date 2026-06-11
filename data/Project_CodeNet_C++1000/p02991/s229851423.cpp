#include <bits/stdc++.h>

using namespace std;

#define node first
#define state second

const int N = 1e5 + 5;
vector<int> adj[N];
bool vis[N][3];

int main() {
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    int n , m;
    cin >> n >> m;

    while (m--) {
        int u , v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    int s , e;
    cin >> s >> e;

    queue<pair<int , int> > q;
    q.push({s , 0});
    vis[s][0] = 1;

    int dep = 0;
    while (q.size()) {
        int sz = q.size();
        while (sz--) {
            auto &cur = q.front();
            q.pop();

            if (cur.node == e && !cur.state) {
                cout << dep / 3;
                return 0;
            }

            for (int child : adj[cur.node]) {
                if (!vis[child][(cur.state + 1) % 3]) {
                    q.push({child , (cur.state + 1) % 3});
                    vis[child][(cur.state + 1) % 3] = 1;
                }
            }
        }
        dep++;
    }

    cout << -1;
}
