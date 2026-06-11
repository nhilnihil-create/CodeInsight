#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using P = pair<int, int>;
using vec = vector<int>;
using mat = vector<vector<int>>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define endl "\n"

constexpr int MOD = 1000000007;
const int INF = 1 << 30;
const int MAX = 510000;

long long fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

long long PER(int n, int k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return (fac[n] * finv[n-k]) % MOD;
}

int main() {
    int n, k;
    cin >> n >> k;
    vec g[100010];
    rep(i, n-1) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    COMinit();

    vec chs(n, -1);
    vec dist(n, INF);
    dist[0] = 0;

    queue<int> que;
    que.push(0);

    while (!que.empty()) {
        int v = que.front();
        que.pop();

        int cnt = 0;

        for (auto&& c : g[v]) {
            if (dist[c] == INF) {
                dist[c] = dist[v] + 1;
                cnt++;
                que.push(c);
            }
        }
        chs[v] = cnt;
    }

    lint res = k;

    rep(i, n) {
        if (i == 0) {
            res *= PER(k-1, chs[i]);
        }
        else {
            res *= PER(k-2, chs[i]);
        }
        res %= MOD;
    }

    cout << res << endl;
    return 0;
}