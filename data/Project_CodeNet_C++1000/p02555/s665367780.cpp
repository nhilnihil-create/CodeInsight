#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for(int i = 0; i < (n); ++i)

int mod = 1e9+7;
int main()
{
    int n;
    cin >> n;
    int dp[n+1] = {0};
    dp[0] = 1;
    for (int i=1; i<=n; i++) {
        for (int j=0; j<=i-3; j++) {
            dp[i] += dp[j];
            dp[i] %= mod;
        }
    }
    cout << dp[n] << endl;
    return 0;
}