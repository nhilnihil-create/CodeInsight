#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
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

struct Edge { int to, id;};

vector<vector<Edge>> G;
vi ans;
int n_col;

void dfs(int v, int pc, int p=-1) {
    int color = 1;
    for (Edge e : G[v]) {
        if (e.to == p) continue;
        if (color == pc) color++;
        ans[e.id] = color;
        dfs(e.to, color, v);
        chmax(n_col, color);
        color++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    G.resize(n);
    rep(i, n-1) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].pb(Edge{b, i});
        G[b].pb(Edge{a, i});
    }
    ans.resize(n-1);
    dfs(0, 0);
    cout << n_col << endl;
    rep(i, n-1) cout << ans[i] << endl;
}