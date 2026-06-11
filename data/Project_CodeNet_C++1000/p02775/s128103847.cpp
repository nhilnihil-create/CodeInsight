#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

// i: 何桁目か
// j: 繰り下がりがあるかどうか
ll dp[10100100 + 10][2];

string S;
ll N;
int main() {
    cin >> S;

    reverse(S.begin(), S.end());
    S += '0';

    N = S.size();

    rep(i, N + 1)rep(j, 2) dp[i][j] = INF;
    dp[0][0] = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 2; j++) {
            int x = S[i] - '0';

            // 遷移
            for (int a = 0; a <= 9; a++) {
                int ni = i + 1, nj = 0;
                int b = (a - j) - x;
                if (b < 0) {
                    nj = 1;
                    b += 10;
                }

                dp[ni][nj] = min(dp[ni][nj], dp[i][j] + a + b);
            }
        }
    }

    cout << dp[N][0] << endl;
}