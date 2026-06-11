#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 3005, M = 998244353;
ll dp[N][N], a[N];

int main() {
    int n, s;
    cin >> n >> s;
    for (int i = 1; i <= n; i++) cin >> a[i];
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= s; j++) {
            dp[i][j] = 2 * dp[i - 1][j] % M;
            if (a[i] <= j) dp[i][j] = (dp[i][j] + dp[i - 1][j - a[i]]) % M;
        }
    }
    cout << dp[n][s];
}
