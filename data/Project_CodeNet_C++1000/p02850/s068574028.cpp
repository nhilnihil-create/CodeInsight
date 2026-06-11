#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
int N;

void solve() {
    cin >> N;
    vector<P> edges;
    vector<vector<int>> g(N);
    int maxNodeNum = 0;
    int maxN = 0;
    for (int i = 0; i < N - 1; ++i) {
        int a, b; cin >> a >> b; a--; b--;
        edges.push_back(P(a, b));
        g[a].push_back(b);
        g[b].push_back(a);
        if (maxN < (int)g[a].size()) {
            maxNodeNum = a;
            maxN = (int)g[a].size();
        }
        if (maxN < (int)g[b].size()) {
            maxNodeNum = b;
            maxN = (int)g[b].size();
        }
    }
    map<P, int> I;
    vector<int> gc(N, 0);
    vector<bool> memo(N, false);
    queue<int> q;
    q.push(maxNodeNum);
    memo[maxNodeNum] = true;
    while(!q.empty()) {
        int node = q.front(); q.pop();
        int cur = 1;
        for (int n_node : g[node]) {
            if (memo[n_node]) continue;
            if (cur == gc[node]) cur++;
            gc[n_node] = I[P(node, n_node)]=I[P(n_node, node)] = cur++;
            memo[n_node] = true;
            q.push(n_node);
        }
    }

    cout << maxN << endl;
    for (int i = 0; i < N-1; ++i) {
        P e = edges[i];
        printf("%d\n", I[e]);
    }
}

int main() {
    solve();
    return 0;
}
