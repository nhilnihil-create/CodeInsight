#include <bits/stdc++.h>
#define DAU  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PLEC exit(0);
using namespace std;
int dp[100005], n, h[100005], res;
int main() {
    DAU
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> h[i];
    for (int i = n - 1; i; --i) {
        if (h[i+1] > h[i])
            dp[i] = 0;
        else dp[i] = dp[i+1] + 1;
        res = max(res, dp[i]);
    }
    cout << res;
    PLEC
}
