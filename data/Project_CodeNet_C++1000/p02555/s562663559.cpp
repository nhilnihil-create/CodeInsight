#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i < (int)n; ++i)

typedef long long ll;

const ll MOD = 1e9 + 7;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int S;
    cin >> S;

    vector<ll> dp(S + 1, 0);

    dp[0] = 1;

    for (int i = 3; i <= S; ++i) {
        for (int j = 0; j <= i - 3; ++j) {
            dp[i] += dp[j];
            dp[i] %= MOD;
        }
    }

    cout << dp[S] << endl;
}