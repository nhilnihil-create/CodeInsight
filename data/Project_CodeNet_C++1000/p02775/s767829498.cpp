#include <bits/stdc++.h>
#define REP(i, start, end) for (int64_t i=start, i##Len=(end); i < i##Len; ++i)
#define REPR(i, start, end) for (int64_t i=start, i##Len=(end); i > i##Len; --i)
using ll = int64_t;
using namespace std;


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    string S;
    cin >> S;
    ll N = S.size(), inf = 1ll << 60;
    vector<vector<ll>> dp(N+1, vector<ll>(2, inf));
    dp[0][0] = 0;

    REP(i, 0, N) {
        ll d = S[N-1-i] - '0';
        dp[i+1][0] = min({
            dp[i][0] + d,
            dp[i][1] + d + 1
        });
        dp[i+1][1] = min({
            dp[i][0] + (10 - d),
            dp[i][1] + (9 - d)
        });
    }

    cout << min(dp[N][0], dp[N][1] + 1) << endl;

}
