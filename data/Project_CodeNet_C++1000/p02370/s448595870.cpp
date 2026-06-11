#include <vector>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <climits>
#include <queue>

using namespace std;

const int V = 10001;
vector<int> adj[V];
bool marked[V];
int degree[V];
vector<int> ans;

void bfs(int s) {
    queue<int> q;
    q.push(s);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < adj[u].size(); ++i) {
            degree[adj[u][i]]--;
            if (degree[adj[u][i]] == 0) {
                q.push(adj[u][i]);
            }
        }

        marked[u] = true;
        ans.push_back(u);
    }
}

int main() {
    int v, e;
    cin >> v >> e;
    for (int i = 0; i < e; ++i) {
        int s, t;
        cin >> s >> t;
        adj[s].push_back(t);
        degree[t]++;
    }

    for (int i = 0; i < v; ++i) {
        if (!marked[i] && degree[i] == 0) {
            bfs(i);
        }
    }

    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << endl;
    }

    return 0;
}
