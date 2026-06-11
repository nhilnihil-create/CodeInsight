#include <bits/stdc++.h>
#define repl(i, l, r) for (int i = l; i < r; ++i)
#define rep(i, n) repl(i, 0, n)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define chmax(x,y) x = max(x, y)
#define chmin(x,y) x = min(x, y)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using G = vector<vector<int>>;
const int MOD = 1000000007;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, -1, 0, 1};

vector<int> to[200005];
vector<int> ans;

void dfs(int v, int p = -1) {
    for(int u : to[v]) {
        if(u == p) continue;
        ans[u] += ans[v];
        dfs(u, v);
    }
}

int main()
{
    int n, q;
    cin >> n >> q;
    rep(i, n-1) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        to[a].pb(b);
        to[b].pb(a);
    }
    ans.resize(n);
    rep(i, q) {
        int p, x;
        cin >> p >> x;
        --p;
        ans[p] += x;
    }
    dfs(0);
    rep(i, n) {
        cout << ans[i] << endl;
    }
    return 0;
}
