#include <bits/stdc++.h>
#define REP(i, m, n) for(int (i) = (m); (i) < (n); ++i)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
using namespace std;
using Graph = vector<vector<int>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
typedef long long ll;
typedef pair<ll, ll> P;
const int INF = 1e9+7;
const ll LINF = 1LL<<60;

const int MAX = 510000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

long long COM(int n, int k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    ll n, k;
    cin >> n >> k;

    Graph G(n);
    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<ll> color(n, -1);
    queue<int> que;
    que.push(0);
    color[0] = k;

    COMinit();

    while(!que.empty()) {
        int v = que.front();
        que.pop();
        int m = G[v].size();
        int i = 1;
        for (auto nv : G[v]) {
            if (color[nv] != -1) continue;
            if (v == 0) color[nv] = k - i;
            else color[nv] = k - 1 - i;
            ++i;
            que.push(nv);
        }
    }

    ll res = 1;
    rep(i, n) {
        if (color[i] == -1) continue;
        res = res * color[i] % MOD;
    }

    cout << res << endl;

    return 0;
}