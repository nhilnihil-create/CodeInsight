#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, T;
    cin >> N >> T;
    vector<ll> A(N), B(N);
    rep(i, N) { cin >> A[i] >> B[i]; }

    ll dp1[N + 5][T + 5];
    memset(dp1, 0, sizeof(dp1));
    rep(i, N) {
        rep(j, T) {
            if (j - A[i] >= 0)
                dp1[i + 1][j] = max(dp1[i + 1][j], dp1[i][j - A[i]] + B[i]);
            dp1[i + 1][j] = max(dp1[i + 1][j], dp1[i][j]);
        }
    }

    ll dp2[N + 5][T + 5];
    memset(dp2, 0, sizeof(dp2));
    for (int i = N - 1; i >= 1; i--) {
        for (int j = 0; j <= T - 1; j++) {
            if (j - A[i] >= 0)
                dp2[i + 1][j] = max(dp2[i][j], dp2[i + 2][j - A[i]] + B[i]);
            dp2[i + 1][j] = max(dp2[i + 1][j], dp2[i + 2][j]);
        }
    }

    ll ans = 0;
    for (int i = 0; i <= N - 1; i++) {
        for (int j = 0; j < T; j++) {
            ll tmp = dp1[i][T - 1 - j] + dp2[i + 2][j];
            tmp += B[i];
            ans = max(tmp, ans);
        }
    }

    cout << ans << endl;
}