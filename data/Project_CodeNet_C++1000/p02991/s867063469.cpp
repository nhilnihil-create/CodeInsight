#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    rep(i, M) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        G[u].push_back(v);
    }
    int S,T;
    cin >> S >> T;
    --S,--T;

    vector<vector<int>> d(N, vector<int>(3, -1));
    d[S][0] = 0;
    queue<pair<int, int>> q;
    q.push({S, 0});

    while (!q.empty()) {
        int u = q.front().first;
        int c = q.front().second;
        q.pop();

        for (auto e : G[u]) {
            if(d[e][(c+1)%3] != -1) continue;
            q.push({e,(c+1)%3});
            d[e][(c+1)%3] = d[u][c] + 1;
        }
    }
    if(d[T][0] == -1) {
        cout << -1 << endl;
        return 0;
    }
    cout << d[T][0]/3 << endl;
}