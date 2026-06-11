#include <bits/stdc++.h>

#define PB emplace_back

using namespace std;

const int N = 5e5+100;

int par[N], sz[N];

vector<int>com[N];

int fat(int x) {
    while(x != par[x]) x = par[x];
    return x;
}

void add(int u, int v) {
    u = fat(u);
    v = fat(v);
    if(u != v) {
        if(sz[u] < sz[v]) swap(u, v);
        sz[u] += sz[v];
        for(int uu: (com[v])) com[u].PB(uu);
        par[v] = u;
        com[v].clear();
    }
}

int main () {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n, m;
    cin >> n >> m;
    iota(par, par + n , 0);
    fill(sz, sz + n, 1);
    for(int i = 0 ; i < n ; i++ ) {
        com[i].PB(i);
    }
    while(m--) {
        int t, u1, u2;
        cin >> t >> u1 >> u2;
        if(t) cout << (fat(u1) == fat(u2)) << '\n';
        else add(u1, u2);
    }
}
