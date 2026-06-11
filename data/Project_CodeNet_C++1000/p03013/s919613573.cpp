#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;
const int mod = 1e9 + 7;


int main() {
    int n, m; cin >> n >> m;
    V<int> v(m);
    for(int i = 0; i < m; i++) cin >> v[i];

    V<int> dp(n + 1, 0);
    for(int i = 0; i < m; i++){
        dp[v[i]] = -1;
    }

    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        if(dp[i] < 0) continue;
        if(0 <= dp[i - 1])dp[i] += dp[i - 1];
        if(1 < i && 0 <= dp[i - 2]) dp[i] += dp[i - 2];
        dp[i] %= mod;
    }
    cout << dp[n] << endl;



    return 0;
}
