#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> g;
vector<int> ans;

int dfs(int v, int p, int c) {
    int color = 1;
    int res = c;
    for (auto e: g[v]) {
        if (e.first == p) continue;
        if (color == c) color++;
        ans[e.second] = color;
        res = max(res, dfs(e.first, v, color));
        color++;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    g.resize(n);
    ans.resize(n);
    for (int i = 0; i < n-1; ++i) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(make_pair(b, i));
        g[b].push_back(make_pair(a, i));
    }
    int c_num = dfs(0, -1, -1);
    cout << c_num << endl;
    for (int i = 0; i < n-1; ++i) {
        cout << ans[i] << endl;
    }
    return 0;
}