#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define MOD 1000000007

ll dp[2000];

int main() {
    ll s;
    cin >> s;
    dp[0] = 1;
    rep2(i, 3, s + 1) {
        dp[i] = dp[i - 1] + dp[i - 3];
        dp[i] %= MOD;
    }
    cout << dp[s] << endl;
    return 0;
}
