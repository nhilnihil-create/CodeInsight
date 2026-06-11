#include <bits/stdc++.h>
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

typedef vector<vector<int>> Graph;

Graph G;
vector<int> seen;
vector<int> d;

void dfs(int node, int value) {
    seen[node] = 1;
    d[node] = value;
    for (int to: G[node]) {
        if (seen[to] == 0)
            dfs(to, value);
    }
}

void Main()
{
    ll n, M;
    cin >> n >> M;

    vector<ll> A(M), B(M);
    rep(i, M) cin >> A[i] >> B[i];
    
    G.assign(n, vector<int>());
    seen.assign(n, 0);
    d.assign(n, 0);
    rep(i, M) {
        G[B[i]-1].push_back(A[i]-1);
        G[A[i]-1].push_back(B[i]-1);
    }

    rep (i, n) {
        if (seen[i] == 0) {
            dfs(i, i);
        }
    }

    vector<ll> cnt(n);
    rep(i, n) {
        cnt[d[i]]++;
    }

    put(*max_element(all(cnt)));
}
signed main(){ Main();return 0;}