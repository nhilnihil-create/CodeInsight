#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

int N, Q;
const int MAX = 200005;
int P[MAX]; // P[i] = j => iの親j
int C[MAX];
Graph G(MAX);

void dfs(int i) {
    for (auto j : G[i]) {
        if (P[j] == -1) {
            P[j] = i;
            C[j] += C[i];
            dfs(j);
        }
    }
}

int main() {
    cin >> N >> Q;

    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    for (int i = 0; i < N; ++i) C[i] = 0;

    for (int i = 0; i < Q; ++i) {
        int p;
        ll x;
        cin >> p >> x;
        --p;
        C[p] += x;
    }

    memset(P, -1, sizeof(P));
    P[0] = 0;
    dfs(0);

    for (int i = 0; i < N; ++i) {
        if (i) cout << ' ';
        cout << C[i];
    }
    cout << endl;
}