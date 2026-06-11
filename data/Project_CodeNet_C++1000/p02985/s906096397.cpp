#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
const int mod = 1e9 + 7, A = 1e5 + 2;
int n, k;
vector<int> v[A];
int add(int x, int y) {
    return ((x + y) % mod + mod) % mod;
}
int mul(int x, int y) {
    return (1LL * x * y) % mod;
}
int DFS(int node, int par) {
    int ret = 1, avail = add(k, -add(1, (par != node)));
    for (auto to : v[node]) {
        if (to == par) continue;
        ret = mul(ret, mul(avail--, DFS(to, node)));
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v[x].pb(y), v[y].pb(x);
    }
    cout << mul(DFS(1, 1), k);
    return 0;
}
