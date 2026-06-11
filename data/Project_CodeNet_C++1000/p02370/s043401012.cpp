#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxV = 10005;

vector<int> to[maxV];

bool visited[maxV];
void dfs(int i, vector<int>& ans) {
    if (visited[i]) return;
    visited[i] = true;
    for (int e : to[i]) {
        dfs(e, ans);
    }
    ans.push_back(i);
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int V, E;
    cin >> V >> E;
    for (int i = 0; i < E; i++) {
        int s, t;
        cin >> s >> t;
        to[s].push_back(t);
    }
    vector<int> ans;
    for (int i = 0; i < V; i++) {
        dfs(i, ans);
    }
    for (int i = V - 1;  i>= 0; i--) {
        cout << ans[i] << endl;
    }
    return 0;
}
