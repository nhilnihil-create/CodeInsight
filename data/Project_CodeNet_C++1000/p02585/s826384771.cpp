#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
const int MOD = 1000000009;
const long long INF = 1LL << 60;

int main() {
    int N , K;
    cin >> N >> K;
    vector<ll> P(N), C(N);
    for (int i = 0; i < N; ++i) cin >> P[i], --P[i];
    for (int i = 0; i < N; ++i) cin >> C[i];

    // solve
    vector<vector<int>> next(60, vector<int>(N));
    vector<vector<ll>> val(60, vector<ll>(N)), all(60, vector<ll>(N));
    for (int v = 0; v < N; ++v) {
        next[0][v] = P[v];
        val[0][v] = all[0][v] = C[v];
    }

    for (int d = 0; d + 1 < 60; ++d) {
        for (int v = 0; v < N; ++v) {
            next[d+1][v] = next[d][next[d][v]];
            val[d+1][v] = val[d][v] + val[d][next[d][v]];
            all[d+1][v] = max(all[d][v], val[d][v] + all[d][next[d][v]]);
        }
    }
    ll res = -INF;
    for (int v = 0; v < N; ++v) {
        ll sum = 0;
        ll offset = v;
        for (int d = 59; d >= 0; --d) {
            if (K & (1LL<<d)) {
                res = max(res, sum + all[d][offset]);
                sum += val[d][offset];
                offset = next[d][offset];
            }
        }
    }
    cout << res << endl;
    return 0;
}