// 6/26 解き直し → 6/30
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

const int INF = 1000000009;

int dp[1010][5000];
int N, M;
vector<vector<int>> c;

int get_nj(int x, int key) {
    vector<int> X;  // (N);
    rep(i, N) {
        X.push_back(x%2);
        x /= 2;
    }

    for (auto y : c[key]) X[y] = 1;

    int res = 0;
    int digit = 1;
    rep(i, N) {
        res += digit * X[i];
        digit *= 2;
    }

    // return 0;
    return res;
}

int main() {
    cin >> N >> M;

    vector<int> a(M), b(M);
    c.resize(M);

    // while (M--)
    rep(i, M) {
        cin >> a[i] >> b[i];
        c[i].resize(b[i]);
        rep(j, b[i]) {
            cin >> c[i][j];
            c[i][j]--;
        }
    }

    rep(i, M+1) rep(j, 1<<N) dp[i][j] = INF;
    dp[0][0] = 0;

    for (int i = 0; i < M; i++) {
        rep(j, 1<<N) {
            // if (dp[i][j] == -1) continue;
            // i番目の鍵を使わない場合
            dp[i+1][j] = min(dp[i+1][j], dp[i][j]);

            // i番目の鍵を使う場合
            int nj = get_nj(j, i);
            dp[i+1][nj] = min(dp[i+1][nj], dp[i][j] + a[i]);
        }
    }

    // printf("dp[%d][%d] = %d\n", M, (1<<N)-1, dp[M][(1<<N)-1]);
    if (dp[M][(1<<N)-1]==INF) cout << "-1" << endl;
    else cout << dp[M][(1<<N)-1] << endl;
}