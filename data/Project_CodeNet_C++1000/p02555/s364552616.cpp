// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
// #include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
using namespace std;
// using namespace atcoder;
using ll = long long;
const int mod = 1e9 + 7;

void solve()
{
    int s;
    cin >> s;
    vector<ll> dp(2020);
    dp[3] = 1;
    rep(i, s + 1)
    {
        if (i > 3)
            dp[i] = dp[i - 3] % mod + dp[i - 1] % mod;
        dp[i] %= mod;
    }
    cout << dp[s] << endl;
}

int main()
{
    // srand((unsigned)time(NULL));
    // int t = clock();
    solve();
    // double et = 1.0 * (clock() - t) / CLOCKS_PER_SEC;
    // printf("Execution Time: %.4lf sec\n", et);
    return 0;
}