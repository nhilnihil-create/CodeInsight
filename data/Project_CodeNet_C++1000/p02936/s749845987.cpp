#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

int N, Q;
vector<vector<int>> G(N, vector<int>());

void dfs(int s, vector<int> &counter, vector<bool> &seen) {
    seen[s] = true;
    for (auto ns : G[s]) {
        if (seen[ns])
            continue;
        counter[ns] += counter[s];
        dfs(ns, counter, seen);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> Q;
    G.resize(N, vector<int>());

    rep(i, N - 1) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<int> counter(N, 0);
    vector<bool> seen(N, false);
    rep(i, Q) {
        int a, b;
        cin >> a >> b;
        a--;
        counter[a] += b;
    }

    dfs(0, counter, seen);

    rep(i, N) { cout << counter[i] << " "; }
    cout << endl;
}