#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

int main()
{
    int v, e;
    cin >> v >> e;
    vector<vector<int>> adj(v, vector<int>());
    vector<int> indeg(v, 0);
    for (int i = 0; i < e; i++) {
        int s, t;
        cin >> s >> t;
        adj[s].push_back(t);
        indeg[t]++;
    }

    queue<int> q;
    for (int i = 0; i < v; i++) {
        if (indeg[i] == 0) {
            q.push(i);
        }
    }

    vector<int> ans;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        ans.push_back(u);
        for (auto v : adj[u]) {
            indeg[v]--;
            if (indeg[v] == 0) {
                q.push(v);
            }
        }
    }

    for (auto u : ans) {
        cout << u << endl;
    }
}
