#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD = 998244353;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, S; cin >> n >> S;
    vector<LL> dp(S + 1, 0);
    dp[0] = 1;
    for (int i = 0 ; i < n ; i++) {
        int v; cin >> v;
        for (int j = S; j >= 0 ; j--) {
            (dp[j] *= 2) %= MOD;
            if (j - v >= 0)
                (dp[j] += dp[j - v]) %= MOD;
        }
    }
    cout << dp.back() << '\n';
}