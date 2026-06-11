#include <bits/stdc++.h>
typedef long long int LL;
typedef unsigned long long int ULL;
using namespace std;

// 插入此處
const int MAXN = 1e5 + 2;
vector<int> adj[MAXN*3];
int ans[MAXN*3];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M; cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v+N);
        adj[u+N].push_back(v+2*N);
        adj[u+2*N].push_back(v);
    }
    int S, T; cin >> S >> T;
    memset(ans, -1, sizeof(ans));
    queue<int> q;
    ans[S] = 0;
    q.push(S);
    while (q.size()) {
        int u = q.front(); q.pop();
        for (auto x : adj[u]) {
            if (ans[x] != -1)  continue;
            ans[x] = ans[u]+1;
            q.push(x);
        }
    }
    cout << (ans[T] == -1 ? -1 : ans[T] / 3) << endl;
    return 0;
}
