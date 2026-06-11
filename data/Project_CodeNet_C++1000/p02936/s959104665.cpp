#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &T, vector<int> &counter, int v, int parent) {
    for (int next_v : T[v]) {
        if (next_v == parent) continue;
        counter[next_v] += counter[v];
        dfs(T, counter, next_v, v);
    }
}

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<vector<int>> T(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        T[a].push_back(b);
        T[b].push_back(a);
    }
    vector<int> counter(N);
    for (int i = 0; i < Q; i++) {
        int p, x;
        cin >> p >> x;
        p--;
        counter[p] += x;
    }

    dfs(T, counter, 0, -1);

    for (int i = 0; i < N; i++) {
        if (i) cout << " ";
        cout << counter[i];
    }
    cout << endl;
}