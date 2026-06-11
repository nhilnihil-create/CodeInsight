#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1000000007;
const long long INF = 1LL << 60;

int main()
{
    ll h, n;
    cin >> h >> n;
    vector<ll> A(n), B(n);
    rep(i, n) cin >> A[i] >> B[i];
    //配るDPで実装→hの例外処理が扱いやすい
    vector<vector<ll>> dp(n + 1, vector<ll>(h + 1, INF));
    rep(i, h + 1) dp[0][0] = 0;

    for (int i = 0; i <= n - 1; i++)
    {
        for (int j = 0; j <= h; j++)
        {
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]); //一度もi番目の魔法を使わない
            dp[i + 1][min(j + A[i], h)] = min(dp[i + 1][min(j + A[i], h)], dp[i + 1][j] + B[i]);
        }
    }

    cout << dp[n][h] << endl;
}

//体力jを満たす最小の魔力のDPテーブル→ぴったりないとinfが答えになってまう