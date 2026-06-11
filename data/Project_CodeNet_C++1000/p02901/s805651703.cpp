#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

int main() {
    int N, M;
    cin >> N >> M;
    vector<ll> a(M), b(M), c(M, 0); // cの集合はbitで表す
    rep(i, M) {
        cin >> a[i] >> b[i];
        rep(j, b[i]) {
            int t;
            cin >> t;
            t--;
            c[i] |= (1 << t);
        }
    }

    vector<vector<ll>> dp(1100, vector<ll>(5000, INF));
    dp[0][0] = 0;

    rep(i, M) {
        rep(j, (1 << N)) {
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);

            int nj = j | c[i]; // i番目の鍵を使う時の次の集合をbitで

            dp[i + 1][nj] = min(dp[i + 1][nj], dp[i][j] + a[i]);
        }
    }

    cout << (dp[M][(1 << N) - 1] < INF ? dp[M][(1 << N) - 1] : -1) << endl;
}