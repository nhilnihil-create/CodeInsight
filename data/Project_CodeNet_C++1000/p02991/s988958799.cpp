#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX_N = 1e5;
vector<vector<int> > G(3*(MAX_N+10));

int main() {
    ll N, M; cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v;
        G[u*3].push_back(v*3+1);
        G[u*3+1].push_back(v*3+2);
        G[u*3+2].push_back(v*3);
    }
    ll S, T; cin >> S >> T;
    vector<bool> visited(3*(N+10), false);
    queue<pair<int, int>> q;
    visited[S*3] = true;
    q.push({S*3, 0});
    while (!q.empty()) {
        pair<int, int> obj = q.front();
        q.pop();
        if (obj.first == T*3) {
            cout << obj.second / 3 << endl;
            return 0;
        }
        for (int x : G[obj.first]) {
            if (!visited[x]) {
                visited[x] = true;
                q.push({x, obj.second + 1});
            }
        }
    }
    cout << -1 << endl;
    return 0;
}
