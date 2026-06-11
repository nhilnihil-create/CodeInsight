#include <bits/stdc++.h>

using namespace std;

using Graph = vector<vector<int>>;

vector<bool> seen;
vector<long long> cnt;
void dfs(const Graph &G, int v) {
    seen[v] = true;
    
    for(auto next_v : G[v]) {
        if(seen[next_v]) continue;
        cnt[next_v] += cnt[v];
        dfs(G, next_v);
    }
}

void solve() {
    int N, Q;
    cin >> N >> Q;
    int a, b;
    Graph G(N);
    for (int i = 0; i < N-1; i++)
    {
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    cnt.assign(N, 0);
    int p, x;
    for (int i = 0; i < Q; i++)
    {
        cin >> p >> x;
        p--;
        cnt[p] += x;
    }
    seen.assign(N, false);
    dfs(G, 0);

    for (int i = 0; i < N; i++)
    {
        cout << cnt[i] << endl;
    }
    
}

int main() {
    solve();
    return 0;
}