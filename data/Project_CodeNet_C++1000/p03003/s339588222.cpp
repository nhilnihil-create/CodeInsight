#include<bits/stdc++.h>

#define M ll(1e9 + 7)

#define maxn 2003

using namespace std;
typedef long long ll;

int n, m;

int a[maxn];
int b[maxn];

ll dp[maxn][maxn];

int main(){
   // #define TASK "ABC"
    //freopen(TASK".inp", "r", stdin); freopen(TASK".out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    cin >> n >> m;

    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 1; i <= m; ++i)
        cin >> b[i];

    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i)
        dp[i][0] = 1;

    for (int j = 1; j <= m; ++j)
        dp[0][j] = 1;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1] - (a[i] == b[j] ? 0 : dp[i - 1][j - 1]) + M) % M;


    cout << dp[n][m];
    return 0;
}
