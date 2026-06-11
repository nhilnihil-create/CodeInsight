#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> tree(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].emplace_back(v);
    }
    int s, t;
    cin >> s >> t;
    queue<pair<int, int>> q;
    q.emplace(pair<int, int>{s, 0});
    vector<vector<bool>> reached(3, vector<bool>(n + 1, false));
    vector<vector<int>> dis(3, vector<int>(n + 1, -1));
    reached[0][s] = true;
    dis[0][s] = 0;
    while (!q.empty()) {
        auto front = q.front();
        q.pop();
        int cur = front.first;
        int count = front.second;
        for (auto e: tree[cur]) {
            if (!reached[(count + 1) % 3][e]) {
                q.emplace(pair<int, int>{e, count + 1});
                reached[(count + 1) % 3][e] = true;
                dis[(count + 1) % 3][e] = count + 1;
            }
        }
    }
    if (dis[0][t] > 0) {
        cout << dis[0][t] / 3 << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}
