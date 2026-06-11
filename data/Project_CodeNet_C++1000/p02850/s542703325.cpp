#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vc = vector<char>;
using vb = vector<bool>;
using vs = vector<string>;
using vll = vector<long long>;
using vp = vector<pair<int, int>>;
using vvi = vector<vector<int>>;
using vvc = vector<vector<char>>;
using vvll = vector<vector<long long>>;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}

int mx = 0;
int n;
struct Edge {
    int to, id;
};
vector<vector<Edge>> g;
vi ans;

void dfs(int v, int c=0, int p=-1) {
    int nxt = 1;
    for (Edge e : g[v]) {
        int u = e.to;
        if (u == p) continue;
        if (nxt == c) nxt++;
        ans[e.id] = nxt;
        dfs(u, nxt, v);
        chmax(mx, nxt);
        nxt++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    g.resize(n);
    rep(i, n-1) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].pb(Edge{b, i});
        g[b].pb(Edge{a, i});
    }
    ans.resize(n);
    dfs(0);
    cout << mx << endl;
    rep(i, n-1) cout << ans[i] << endl; 
}