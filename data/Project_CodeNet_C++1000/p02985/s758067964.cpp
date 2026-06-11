#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

typedef long long ll;

template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

const ll MOD = ll(1e9 + 7);

vector<vector<int>> edges;

void solve(const ll ppre, const ll pre, const ll prev, const int cur, ll &acc, const ll N, const ll K) {
    acc = (acc * (K - ppre - pre)) % MOD;
    // printf("%lld\n", acc);
    ll x = 0;
    for (auto &next : edges[cur]) {
        if (next == prev) continue;
        solve(pre + x, 1LL, cur, next, acc, N, K);
        x++;
    }
}

int main(void) {
    int N, K;
    cin >> N >> K;

    edges.resize(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    ll ans = 1;
    solve(0, 0, -1, 0, ans, N, K);
    cout << ans << endl;

    return 0;
}
