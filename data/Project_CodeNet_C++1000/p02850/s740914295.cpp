#include <bits/stdc++.h>
// #include <atcoder/all>
#define ll long long int
#define ld long double
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, n) for (ll i = 1; i < (ll)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
// using namespace atcoder;

typedef vector<vector<int>> Graph;

Graph G;
unordered_map<int, unordered_map<int, int>> edgeColor;

void dfs(int node, int color) {
    int c = 1;
    edgeColor[node] = unordered_map<int, int>();
    for (int to: G[node]) {
        if (c == color) c++;
        edgeColor[node][to] = c;
        dfs(to, c);
        c++;
    }
}

void Main()
{
    ll n;
    cin >> n;

    vector<ll> a(n - 1), b(n - 1);
    rep(i, n - 1) cin >> a[i] >> b[i];
    
    G.assign(n, vector<int>());
    rep(i, n - 1) {
        G[a[i] - 1].push_back(b[i] - 1);
    }

    dfs(0, -1);

    int res = 1;
    rep(i, n - 1) {
        res = max(res, edgeColor[a[i] - 1][b[i] - 1]);
    }
    put(res);
    rep(i, n - 1) {
        put(edgeColor[a[i] - 1][b[i] - 1]);
    }

}
signed main(){ Main();return 0;}