#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define rep(i, n) for(int i = 0; i < n; i++)
#define REP(i, a, b) for(int i = a; i <= b; i++)
#define all(x) x.begin(), x.end()
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

vector<int> G[200000];
vector<int> X(200000);
vector<ll> ans(200000);

void dfs(int v = 0, int p = -1) {
    ans[v] += X[v];
    for (auto u : G[v]) {
        if (u == p) continue;
        ans[u] += ans[v];
        dfs(u, v);
    }
}

void solve() {
    int n, q;
    cin >> n >> q;
    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }
    rep(i, q) {
        int p, x;
        cin >> p >> x;
        p--;
        X[p] += x;
    }
    dfs();
    rep(i, n) cout << ans[i] << " \n"[i == n - 1];
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
