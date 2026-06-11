#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e15;

#include <math.h>
#define PI 3.14159265358979323846264338327950L
const int mxN = 1e9 + 7;


int main() {
    int n, m;
    cin >> n >> m;
    vector<bool> d(100001);
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        d[x] = true;
    }
    int cnt = 0;
    bool ok = true;
    for (int i = 1; i <= n; i++) {
        if (d[i]) cnt++;
        else cnt = 0;
        if (cnt >= 2) ok = false;
    }
    if (!ok) {
        cout << 0;
        return 0;
    }
    vector<long long> dp(100001);
    if (!d[1]) dp[1] = 1;
    if (!d[2]) {
        if (d[1]) dp[2] = 1;
        else dp[2] = 2;
    }
    for (int i = 3; i <= n; i++) {
        if (dp[i - 1] == 0) {
            dp[i] = dp[i - 2];
            continue;
        }
        else {
            if (!d[i]) dp[i] = dp[i - 1] + dp[i - 2];
        }
        dp[i] %= MOD;
    }
    cout << dp[n] % MOD;
    
    return 0;
}