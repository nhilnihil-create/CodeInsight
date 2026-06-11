#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    int n, m, u, v, s, t, d[3][100005] = {};
    vector<int> g[100005] = {};
    cin >> n >> m;
    while (m--) cin >> u >> v, g[u].push_back(v);
    cin >> s >> t;
    queue<pii> q;
    q.push({0, s});
    d[0][s] = 1;
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int i : g[y]) {
            if (!d[(x + 1) % 3][i]) d[(x + 1) % 3][i] = d[x][y] + 1, q.push({(x + 1) % 3, i});
        }
    }
    if (d[0][t]) cout << (d[0][t] - 1) / 3;
    else cout << -1;
}
