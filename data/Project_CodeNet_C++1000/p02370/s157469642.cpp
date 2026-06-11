#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int N, M;
    cin >> N >> M;
    int s[M], t[M];
    vector<int> adj[N];
    for (int i = 0; i < M; i++) {
        cin >> s[i] >> t[i];
        adj[s[i]].push_back(t[i]);
    }
    int indeg[N]{};
    int flag[N]{};
    
    int dp[N]{};
    fill(dp, dp + N, -1);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < adj[i].size(); j++) {
            int u = adj[i][j];
            indeg[u]++;
        }
    }
    deque<int> q;
    vector<int> id;
    for (int i = 0; i < N; i++) {
        if (indeg[i] == 0 && flag[i] == 0) {
            q.push_back(i);
            while (!q.empty()) {
                int u = q.front();
                id.push_back(u);
                q.pop_front();
                flag[u] = 1;
                for (int j = 0; j < adj[u].size(); j++) {
                    int v = adj[u][j];
                    indeg[v]--;
                    if (indeg[v] == 0 && flag[v] == 0) {
                        flag[v] = 1;
                        q.push_back(v);
                    }
                }
            }
        }
    }
    
    for (int i : id) {
        cout << i << "\n";
    }
    return 0;
}
