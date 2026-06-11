#include <bits/stdc++.h>

#define PB emplace_back

using namespace std;

const int N = 5e5+100;

int par[N], h[N];

int fat(int x) {
    while(x != par[x]) x = par[x];
    return x;
}

void add(int u, int v) {
    u = fat(u);
    v = fat(v);
    if(u != v) {
        //if(h[u] > h[v]) swap(u, v);
        //h[u] = max(h[u], h[v] + 1);
        par[v] = u;
    }
}

int main () {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n, m;
    cin >> n >> m;
    iota(par, par + n , 0);
    while(m--) {
        int t, u1, u2;
        cin >> t >> u1 >> u2;
        if(t) cout << (fat(u1) == fat(u2)) << '\n';
        else add(u1, u2);
    }
}
