#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<long long> vll;
typedef pair<long long, long long> pll;

const ll INF = 1e15;
const ll MOD = 1e9 + 7;

const ll MAX_N = 1e5;
vll E[MAX_N];
ll ans = 1;
ll K;

void dfs(ll s, ll f, ll sc, ll nc) {
    ans = ans * sc % MOD;
    for(auto e : E[s]) {
        if(e != f) {
            dfs(e, s, nc, K - 2);
            if(nc == 0) {
                return;
            }
            nc--;
        }
    }
    return;
}

int main() {
    ll i, j, k;
    ll N;
    cin >> N >> K;
    for(i = 0; i < N; i++) {
        E[i] = vll(0);
    }
    for(i = 0; i < N - 1; i++) {
        ll a, b;
        cin >> a >> b;
        E[a - 1].push_back(b - 1);
        E[b - 1].push_back(a - 1);
    }
    dfs(0, 0, K, K - 1);
    cout << ans << endl;

    return 0;
}
