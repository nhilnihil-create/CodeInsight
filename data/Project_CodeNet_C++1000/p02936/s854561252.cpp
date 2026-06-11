#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 100000000;
#define rep1(i, n) for (ll i=0; i<(n); i++) 
#define rep2(i, k, n) for (ll i=k; i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

typedef vector<vector<ll> > Graph;

vector<bool> seen;
vector<ll> c;

void dfs(const Graph &G, ll v) {
    seen[v] = true;

    for (auto next_v : G[v]) { 
        if (seen[next_v]) continue;
        c[next_v] += c[v];
        dfs(G, next_v);
    }
}

int main() {
    ll n, q;
    cin >> n >> q;
    Graph G(n);
    rep1(i, n-1){
        ll a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    seen.assign(n, false);
    c.assign(n, 0);
    rep1(i, q){
        ll p, x;
        cin >> p >> x;
        p--;
        c[p] += x;
    }
    dfs(G, 0);
    rep1(i, n){
        if (i==n-1) cout << c[i] << endl;
        else cout << c[i] << " ";
    }
    //printf("%.12f", ans);
}