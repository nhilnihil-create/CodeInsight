#include <bits/stdc++.h>

#define ll long long
#define N (ll)(4*1e6)
#define EPS (double)(1e-12)
#define M (ll)(1e9+7)

using namespace std;

const ll maxN = 1e5+1;

vector<ll> adj[maxN];

void addEdge(ll u, ll v) {
    adj[u].push_back(v);
}
ll mat[maxN][4];

ll bfs(ll s, ll t) {
    queue<pair<ll, ll>> fila;

    // node / distance
    fila.push({s, 0});

    while(!fila.empty()) {
        int no = fila.front().first;
        int dist = fila.front().second;

        fila.pop();

        if(mat[no][dist%3])
            continue;
        mat[no][dist%3] = true;

        if(no == t && dist%3 == 0)
            return dist/3;
        
        for(auto a : adj[no])
            fila.push({a, dist+1});
    }
    return -1;
}

int main() {
    // 189 algorithm design manual
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, m, s, t, u, v;

    cin >> n >> m;

    for(ll i = 0; i < m; i++) {
        cin >> u >> v;
        addEdge(u, v);
    }
    cin >> s >> t;

    cout << bfs(s, t) << endl;


    return 0;
}