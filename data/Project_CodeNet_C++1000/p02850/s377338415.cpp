#include <bits/stdc++.h>

using namespace std;

const int M = 1e5 + 5;

int n, k = 0, colors[M];
vector<array<int, 2>> g[M];

void DFS(int x, int p, int clr) {
    int color = 1;
    for (auto a : g[x]) {
        if (a[0] == p) continue;
        if (color == clr) color++;
        colors[a[1]] = color++;
        DFS(a[0], x, colors[a[1]]);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 1, a, b; i < n; i++) {
        cin >> a >> b;
        g[a].push_back({b, i});
        g[b].push_back({a, i});
    } // Max Degree = K (Editorial TIME)
    for (int i = 1; i <= n; i++) k = max(k, (int) g[i].size()); cout << k << '\n';
    DFS(1, -1, -1);
    for (int i = 1; i < n; i++) cout << colors[i] << '\n';

    return 0;
}