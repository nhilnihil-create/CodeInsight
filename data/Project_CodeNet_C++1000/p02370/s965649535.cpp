#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> g;

vector<int> topological_sort(vector<vector<int>> &g) {
    int V = g.size();
    vector<int> ans;

    vector<int> ind(V);
    for (int i = 0; i < V; ++i) for (int x: g[i]) ind[x]++;
    queue<int> Q;
    for (int i = 0; i < V; ++i) if (ind[i] == 0) Q.push(i);
    while (!Q.empty()) {
        int v = Q.front(); Q.pop(); 
        ans.push_back(v);
        for (int x: g[v]) if (--ind[x] == 0) Q.push(x);
    }
    return ans;
}

int main() {
    int v, e;
    cin >> v >> e;
    g.resize(v);
    for (int i = 0; i < e; i++) {
        int s, t;
        cin >> s >> t;
        g[s].push_back(t);
    }

    vector<int> ans = topological_sort(g);

    for (int i = 0; i < v; i++) cout << ans[i] << '\n';
    return 0;
}
