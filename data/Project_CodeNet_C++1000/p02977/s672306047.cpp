#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define forn(i,n) for (int i = 0; i < int(n); i++)

vector<pair<int,int>> adj;

int n;
const int N = 1e5;
bool vis[N];
int dfs(int u, int s, int val) {
    cerr << u << ' ' << s << ' ' << val << endl;
    if (vis[u]) return -1;
    if (u == n+s) return val;
    vis[u] = true;
    for (auto xy : adj) {
        int x,y; tie(x,y) = xy;
        if (x == u || y == u) {
            int v = x+y-u;
            int aa = dfs(v, s, val^(v - n*(v > n)));
            if (aa != -1) return aa;
        }
    }
    return -1;
}

bool check() {
    n = (adj.size()+1)/2;
    for (int u = 1; u <= n; u++) {
        fill_n(vis, 2*n+2, 0);
        int val = dfs(u,u,u);
        if (val != u) {
            cerr << "error " << u << " val = " << val << endl;
            return false;
        }
    }
    return true;
}

bool solve(int n) {
    if (n < 3) return false;
    int r = n%4;

    vector<int> row;
    if (r == 0) {
        int a = n&(-n);
        int b = n-a;
        if (a == n) return false;

        row.push_back(a);
        row.push_back(b);
        for (int i = 1; i < n; i++) if (i != a && i != b) row.push_back(i);
        int sz = row.size();
        forn(i,sz) row.push_back(n + row[i]);
        forn(i, int(row.size())-1) adj.emplace_back(row[i], row[i+1]);
        adj.emplace_back(n, row[0]);
        adj.emplace_back(row[1], n+n);
    }
    else if (r == 1) {
        for (int i = 2; i <= n; i++) row.push_back(i);
        int sz = row.size();
        forn(i,sz) row.push_back(n + row[i]);
        forn(i, int(row.size())-1) adj.emplace_back(row[i], row[i+1]);
        adj.emplace_back(1, row[0]);
        adj.emplace_back(row[1], n+1);
    }
    else if (r == 2) {
        for (auto x : {3,2,n-2}) row.push_back(x);
        for (int i = 4; i < n; i++) if (i != n-2) row.push_back(i);
        int sz = row.size();
        forn(i,sz) row.push_back(n + row[i]);
        forn(i, int(row.size())-1) adj.emplace_back(row[i], row[i+1]);
        adj.emplace_back(1, row[0]);
        adj.emplace_back(row[1], n+1);
        adj.emplace_back(n, row[1]);
        adj.emplace_back(row[2], n+n);
    }
    else {
        forn(i,n) row.push_back(i+1);
        int sz = row.size();
        forn(i,sz) row.push_back(n + row[i]);
        forn(i, int(row.size())-1) adj.emplace_back(row[i], row[i+1]);
    }
    return true;
}

int main() {
    int n; cin >> n;
    bool ans = solve(n);
    if (ans) {
        cout << "Yes\n";
        for (auto uv : adj) {
            int u,v; tie(u,v) = uv;
            cout << u << ' ' << v << '\n';
        }
    }
    else cout << "No\n";
    return 0;
}
