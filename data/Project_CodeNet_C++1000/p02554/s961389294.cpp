#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 6;
const ll mod = 1e9 + 7;
ll dp[maxn][2][2];
int n;
int main () {
    scanf("%d", &n);
    dp[0][0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                for (int t = 0; t < 10; t++) {
                    (dp[i + 1][j || (t == 0)][k || (t == 9)] += dp[i][j][k]) %= mod;
                }
            }
        }
    }
    printf("%lld\n", dp[n][1][1]);

    return 0;
}
