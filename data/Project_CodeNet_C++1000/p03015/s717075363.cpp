#include <bits/stdc++.h>
using namespace std;

using ll = long long;


#define MOD 1000000007

int main(void) {
    string L;
    vector<pair<ll, ll>> dp;
    cin >> L;
    dp.resize(L.size() + 1);
    dp[0].second = 1;
    for(ll i = 0;i < L.size();i++) {
        if(L[i] == '1') {
            dp[i + 1].first += (dp[i].first + dp[i].second) % MOD;
            dp[i + 1].first += 2 * dp[i].first % MOD;
            dp[i + 1].second += 2 * dp[i].second % MOD;
        } else {
            dp[i + 1].first += 3 * dp[i].first % MOD;
            dp[i + 1].second += dp[i].second;
        }
        dp[i + 1].first %= MOD;
        dp[i + 1].second %= MOD;
    }
    cout << (dp[L.size()].first + dp[L.size()].second) % MOD << endl;
    return 0;
}
