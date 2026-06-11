#include <bits/stdc++.h>
typedef long long int LL;
typedef unsigned long long int ULL;
using namespace std;

// 插入此處

LL a[3005];

const LL M = 998244353;

LL dp[3005];

int main() {
    LL n, s;
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = s; j >= a[i]; j--) {
            dp[j] = dp[j] * 2 + dp[j - a[i]];
            dp[j] %= M;
        }
        for (int j = a[i] - 1; j >= 0; j--) {
            dp[j] = dp[j] * 2 % M;
        }
        // for (int j = 0; j <= s; j++) {
        //     printf("dp[%d] = %lld\n", j, dp[j]);
        // }
        // puts("");
    }
    cout << dp[s] << endl;
}
