#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> broken(n+2);
    rep(i,m) {
        int a;
        cin >> a;
        broken[a+1] = 1;
    }
    vector<int> dp(n+2);
    const int mod = 1e9+7;
    dp[1] = 1;
    for (int i = 2; i <= n+1; i++) {
        if (broken[i]) {
            dp[i] = 0;
            continue;
        }
        dp[i] = (dp[i-1]+dp[i-2])%mod;
    }
    cout << dp[n+1] << endl;
    return 0;
}
