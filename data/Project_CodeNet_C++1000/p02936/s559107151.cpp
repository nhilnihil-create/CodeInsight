#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> G;
vector<long long> cnt, visited;

void dfs(int i, int prev = -1) {
    if (visited[i]) return;
    visited[i] = 1;
    if (prev != -1) cnt[i] += cnt[prev];
    for (int j : G[i]) dfs(j, i);
}

int main() {
    int N, Q;  cin >> N >> Q;
    G.resize(N);
    for (int i = 0; i < N - 1; ++i) {
        int a, b;  cin >> a >> b;  --a; --b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    cnt.resize(N);
    visited.resize(N);
    for (int i = 0; i < Q; ++i) {
        int p, x;  cin >> p >> x;  --p;
        cnt[p] += x;
    }
    dfs(0);
    for (int i = 0; i < N; ++i) cout << cnt[i] << " ";
    cout << endl;
}
