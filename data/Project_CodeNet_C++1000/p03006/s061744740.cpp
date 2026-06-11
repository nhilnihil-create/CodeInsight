#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < n; ++i)
ll dx[4] = { 0, 1, 0, -1 };
ll dy[4] = { 1, 0, -1, 0 };
const ll INF = LLONG_MAX;
const ll MOD = 1e9 + 7;

ll N;
vector<ll> x, y;

ll solve()
{
    if (N == 1) {
        return 1;
    }

    ll res = N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i == j) {
                continue;
            }
            ll dx = x[j] - x[i], dy = y[j] - y[i];

            ll sub = 0;
            for (int i2 = 0; i2 < N; ++i2) {
                for (int j2 = 0; j2 < N; ++j2) {
                    if (i2 == j2) {
                        continue;
                    }
                    if (dx == x[j2] - x[i2] && dy == y[j2] - y[i2]) {
                        ++sub;
                    }
                }
            }

            res = min(res, N - sub);
        }
    }
    return res;
}

int main()
{
    cin >> N;
    x.resize(N);
    y.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> x[i] >> y[i];
    }
    cout << solve() << endl;
}