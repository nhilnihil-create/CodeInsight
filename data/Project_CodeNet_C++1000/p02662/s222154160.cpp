#include<bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define pii pair<int,int>

int N, S;
int A[3010];
int dp[3010][3010];
int mod = 998244353;

signed main()
{
    cin >> N >> S;
    rep(i, N)cin >> A[i];

    dp[0][0] = 1;
    rep(i, N)
    {
        rep(j, S + 1)
        {
            // use
            if(j + A[i] <= S)dp[i + 1][j + A[i]] = (dp[i + 1][j + A[i]] + dp[i][j]) % mod;

            // dont
            dp[i + 1][j] = (dp[i + 1][j] + dp[i][j] * 2) % mod;
        }
    }

    cout << dp[N][S] << endl;

    return 0;
}
