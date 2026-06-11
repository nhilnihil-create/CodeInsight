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
vector<ll> d;

void dfs(int node, int parent, ll v) {
    d[node] += v;
    for (int to: G[node]) {
        if (to == parent) continue;
        dfs(to, node, d[node]);
    }
}

void Main()
{
    ll n, Q;
    cin >> n >> Q;

    vector<ll> a(n - 1), b(n - 1);
    rep(i, n - 1) cin >> a[i] >> b[i];

    vector<ll> p(Q), x(Q);
    rep(i, Q) cin >> p[i] >> x[i];
    
    G.assign(n, vector<int>());
    d.assign(n, 0);
    rep(i, n - 1) {
        G[a[i] - 1].push_back(b[i] - 1);
        G[b[i] - 1].push_back(a[i] - 1);
    }

    rep(i, Q) {
        d[p[i]-1] += x[i];
    }

    dfs(0, -1, 0);

    rep(i, n) {
        cout << d[i] << (i == n - 1? "": " ");
    }
    cout <<endl;
}
signed main(){ Main();return 0;}