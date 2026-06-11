#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

vector<bool> seen;
vector<int> p, sum;
void dfs(vector<vector<int>> &g, int v, int &ptr) {
    seen[v] = true;
    ptr += p[v];
    sum[v] += ptr;
    for (auto now : g[v]) {
        if (seen[now])
            continue;
        dfs(g, now, ptr);
    }
    ptr -= p[v];
}
int main() {
    int n, q, a, b;
    cin >> n >> q;
    vector<vector<int>> u(n);
    p.assign(n, 0);
    seen.assign(n, false);
    sum.assign(n, 0);
    rep(i, n - 1) {
        cin >> a >> b;
        u[a - 1].push_back(b - 1);
        u[b - 1].push_back(a - 1);
    }
    rep(i, q) {
        cin >> a >> b;
        p[a - 1] += b;
    }
    int ptr = 0;
    dfs(u, 0, ptr);
    rep(i, n) {
        cout << sum[i] << " ";
    }
    cout << endl;
}