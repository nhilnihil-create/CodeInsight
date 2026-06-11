#include <bits/stdc++.h>
using namespace std;
#define REP(name, stop) for (ll(name) = 0; (name) < (stop); (name)++)
using ll = long long;
using vi = vector<ll>;

constexpr ll N_MAX = 10;
vi A(N_MAX);
constexpr ll Q_MAX = 50;
ll query[Q_MAX][4] = {0};

ll countScore(ll Q) {
    ll score = 0;
    REP(i, Q) {
        ll a_idx = query[i][0];
        ll b_idx = query[i][1];
        ll diff = A[b_idx] - A[a_idx];
        if (diff == query[i][2])
            score += query[i][3];
    }
    return score;
}

ll dfs(ll idx, ll value, ll N, ll M, ll Q) {
    if (idx == N) {
        return countScore(Q);
    }
    ll sc = 0;
    for (ll v = value; v <= M; v++) {
        A[idx] = v;
        sc = max(dfs(idx + 1, v, N, M, Q), sc);
    }
    return sc;
}

int main(void) {
    ll N, M, Q;
    cin >> N >> M >> Q;
    REP(i, Q) {
        cin >> query[i][0] >> query[i][1] >> query[i][2] >> query[i][3];
        query[i][0]--;
        query[i][1]--;
    }
    cout << dfs(0, 1, N, M, Q) << endl;

    return 0;
}
