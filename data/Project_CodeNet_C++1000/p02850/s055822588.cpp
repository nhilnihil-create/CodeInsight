#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define rep(i, n) for(int i = 0; i < n; i++)
#define REP(i, a, b) for(int i = a; i <= b; i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fi first
#define se second
#define debug(...) cerr<<__LINE__<<" ["<<#__VA_ARGS__<<"]:",debug_out(__VA_ARGS__)
template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec)
    { for (auto v : vec) os << v << ' '; os << '\n'; return os; }
template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa)
    { os << '(' << pa.first << ',' << pa.second << ')'; return os; }
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T)
    { cerr << " " << H; debug_out(T...); }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;

vector<pii> G[101010];
vector<int> edge(101010);

void dfs(int v, int p = -1, int pre = -1) {
    int color = 0;
    for (auto &u : G[v]) {
        if (u.fi == p) continue;
        color++;
        if (color == pre) color++;
        dfs(u.fi, v, color);
        edge[u.se] = color;
    }
}

void solve() {
    int n;
    cin >> n;
    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back({b, i});
        G[b].push_back({a, i});
    }
    int maxdeg = 0;
    rep(i, n) {
        chmax(maxdeg, (int)G[i].size());
    }
    dfs(1);
    cout << maxdeg << endl;
    rep(i, n - 1) {
        cout << edge[i] << endl;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
