#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;

int n, q;
vector<vector<int>> G;
vector<int> cnt;
vector<int> res;

void dfs(int v, int p, int add = 0) {
    res[v] = add + cnt[v];
    for (auto nv : G[v]) {
        if (nv == p) continue;
        dfs(nv, v, add + cnt[v]);
    }
}

int main(){
    cin >> n >> q;
    G.resize(n);
    for (int i = 0; i < n-1; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    cnt.assign(n, 0);
    for (int i = 0; i < q; ++i) {
        int p, x;
        cin >> p >> x;
        --p;
        cnt[p] += x;
    }

    res.resize(n);
    dfs(0, -1);
    for (int i = 0; i < n; ++i) {
        cout << res[i] << endl;
    }
}