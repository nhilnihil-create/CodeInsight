#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define ld long double
#define INF 1000000000000000000
typedef pair<ll, ll> pll;
typedef pair<int, int> pint;

int main() {
    int N, M;
    cin >> N >> M;
    vector<ll> a(M), b(M), c(M, 0);
    vector<vector<ll>> dp(1100, vector<ll>(5000, INF));

    rep(i, M) {
        cin >> a[i] >> b[i];
        rep(j, b[i]) {
            int t;
            cin >> t;
            t--;
            c[i] += (1 << t);
        }
    }

    dp[0][0] = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < (1 << N); j++) {
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);

            int nj = j | c[i];
            dp[i + 1][nj] = min(dp[i + 1][nj], dp[i][j] + a[i]);
        }
    }

    cout << (dp[M][(1 << N) - 1] < INF ? dp[M][(1 << N) - 1] : -1) << endl;
}