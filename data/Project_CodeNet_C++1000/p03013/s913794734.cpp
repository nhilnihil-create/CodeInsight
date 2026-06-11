#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const long long mod = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> oks(n + 1, true);
    rep(i, m) {
        int a;
        cin >> a;
        oks[a] = false;
    }

    vector<ll> dp(n + 1);
    dp[0] = 1;
    rep(now, n) {
        for(int next = now + 1; next <= min(n, now + 2); next++) {
            if(oks[next]) {
                dp[next] += dp[now];
                dp[next] %= mod;
            }
        }
    }
    cout << dp[n] << endl;
    return 0;
}