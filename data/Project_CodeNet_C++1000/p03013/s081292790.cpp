#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    long long n, m;

    cin >> n >> m;
    vector<bool> vec(n + 1, true);
    vector<long long> dp(n + 1, 0);

    for (int i = 0; i < m; i++) {
        long long k;
        cin >> k;
        vec.at(k) = false;
    }

    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        if(i==1){
            if (vec.at(i) == true) dp[i] = 1;
            continue;
        }

        if (vec.at(i - 1) == true) dp[i] += dp[i - 1];
        if (vec.at(i - 2) == true) dp[i] += dp[i - 2];
        dp[i] %= 1000000007;
    }

    cout << dp[n];
    //
}
