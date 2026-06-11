#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, k;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    int lim = (n - 1) * (n - 2) / 2;

    if (k > lim) {
        cout << -1;
        return 0;
    }

    vector<pair<int, int>> edges;
    for (int i = 2; i <= n; ++i)
        edges.push_back({1, i});

    for (int i = 2; i < n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (lim > k) {
                edges.push_back({i, j});
                --lim;
            } else break;
        }
    }

    cout << edges.size() << '\n';
    for (auto edge : edges) cout << edge.first << ' ' << edge.second << '\n';
}
