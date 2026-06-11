#include <bits/stdc++.h>
#define ALL(A) (A).begin(), (A).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)

const ll MOD = 1e9 + 7;
const ll INF = -1 * ((1LL << 63) + 1);
const int inf = -1 * ((1 << 31) + 1);

using namespace std;

ll dp[2100][2100];  // dp[i][j] := Sのi文字目までとTのj文字目までを見てペアにしたときの場合の数
ll sdp[2100][2100]; // sdp[i][j]:= : sum = 0 , rep(x,i)rep(y,j)sum+=dp[x][y], sdp[i][j] = sum

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    vector<int> S(N), T(M);
    rep(i, N) cin >> S[i];
    rep(i, M) cin >> T[i];
    dp[0][0] = 1;
    sdp[1][1] = 1;

    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= M; j++)
        {
            dp[i][j] %= MOD;
            sdp[i][j] %= MOD;
            if (i == 0 && j == 0)
                continue;
            if (i - 1 >= 0 && j - 1 >= 0 && S[i - 1] == T[j - 1])
            {
                dp[i][j] = sdp[i][j]%MOD;
                dp[i][j] %= MOD;
            }
            sdp[i + 1][j + 1] = (sdp[i + 1][j]%MOD + sdp[i][j + 1]%MOD - sdp[i][j]%MOD + dp[i][j]%MOD + MOD) % MOD;
            sdp[i + 1][j + 1]%= MOD;
        }
    }
    cout << sdp[N + 1][M + 1] % MOD << endl;
}
