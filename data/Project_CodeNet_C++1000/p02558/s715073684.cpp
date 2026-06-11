/*
https://atcoder.jp/contests/practice2/tasks/practice2_a
*/

#include<bits/stdc++.h>
using namespace std;

bool db = false;
typedef long long LL;
typedef long double LD;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef pair<LL, pll> pl_ll;
typedef pair<pll, LL> pll_l;

const LL INF = 1e18+1;

const LL maxn = 2*1e6+1;

LL t, n, m, q;
//LL a[maxn+1];

int p[maxn];
int r(int u) {
    return p[u] < 0 ? u : p[u] = r(p[u]);
}
bool same(int u, int v) {
    return r(u) == r(v);
}
void merge(int u, int v) {
    u = r(u);
    v = r(v);
    if(u == v)
        return;
    if(p[u] > p[v])
        swap(u, v);
    p[u] += p[v];
    p[v] = u;
}
int main() {

#ifdef MY_FILE_INPUT
    db = false;
    db = true;
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(p, -1, sizeof(p));
    cin >> n >> q;
    for(int i = 0; i < q; i++) {
        int u, v;
        cin >> t >> u >> v;
        if(t == 0) merge(u, v);
        else if(same(u, v)) cout << 1 << endl;
        else cout << 0 << endl;
    }

    return 0;
}