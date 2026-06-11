#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1000000007;

ll N, K;
vector<vector<int>> G;

ll dfs(int u, int parent) {
    ll numOfColors = (parent == -1) ? K - 1 : K - 2;

    if (G[u].size() > K) {
        return 0;
    } else {
        ll res = 1;
        for (int v : G[u]) {
            if (v == parent) continue;

            res *= numOfColors;
            res %= MOD;
            numOfColors--;
        }

        for (int v : G[u]) {
            if (v == parent) continue;

            res *= dfs(v, u);
            res %= MOD;
        }

        return res;
    }
}

int main() {
    cin >> N >> K;
    G.resize(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    ll res = K * dfs(0, -1);
    res %= MOD;

    cout << res << endl;
    return 0;
}