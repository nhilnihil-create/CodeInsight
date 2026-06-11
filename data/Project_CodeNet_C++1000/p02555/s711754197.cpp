#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 2e3 + 10;
const ll MOD = 1e9 + 7;

int n;
ll dp[2][N];
ll ans;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=0;i<2;i++){
        fill(dp[i], dp[i] + N, 0);
    }
    dp[1][0] = 1;
    for (int i=0;i<n/3;i++){
        for (int j=0;j<n;j++){
            dp[0][j] = dp[1][j];
            if (j) dp[0][j] = (dp[0][j] + dp[0][j - 1]) % MOD;
            dp[1][j] = 0;
        }
        for (int j=3;j<=n;j++){
            dp[1][j] = dp[0][j - 3];
        }
        ans = (ans + dp[1][n]) % MOD;
    }
    cout << ans << el;

    return 0;
}