#include <bits/stdc++.h>

#define debug(x) cerr << #x << ": " << x << endl
#define debugArray(x, n)                                                       \
    for(long long hoge = 0; (hoge) < (n); ++(hoge))                            \
    cerr << #x << "[" << hoge << "]: " << x[hoge] << endl
using namespace std;

using ll = long long;
using ull = unsigned long long;
const ll INF = LLONG_MAX / 2;
const ll MOD = 1e9 + 7;

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int N, T;
    cin >> N >> T;
    ll A[N], B[N];
    for(int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }
    ll dp1[N + 1][T] = {}, dp2[N + 1][T] = {};
    for(int i = 0; i < N; i++) {
        for(int t = T - 1; t >= 0; t--) {
            dp1[i + 1][t] = dp1[i][t];
            if(t >= A[i])
                dp1[i + 1][t] = max(dp1[i + 1][t], dp1[i][t - A[i]] + B[i]);
        }
    }
    for(int i = N - 1; i >= 0; i--) {
        for(int t = T - 1; t >= 0; t--) {
            dp2[i][t] = dp2[i + 1][t];
            if(t >= A[i])
                dp2[i][t] = max(dp2[i][t], dp2[i + 1][t - A[i]] + B[i]);
        }
    }
    ll ans = 0;
    for(int i = 0; i < N; i++) {
        for(int t = 0; t < T; t++) {
            ans = max(ans, dp1[i][t] + dp2[i + 1][T - 1 - t] + B[i]);
        }
    }
    cout << ans << endl;
    return 0;
}