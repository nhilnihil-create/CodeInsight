#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;
using ld = long double;
const int MOD = 1e9+7;
const ll INF = 1LL << 60;


int main() {
    int n, m; cin >> n >> m;
    V<bool> b(n + 1, false);
    for(int i = 0; i < m; i++){
        int a; cin >> a;
        b[a] = true;
    }

    V<int> dp(n + 5);
    dp[0] = 1;
    for(int i = 0; i < n; i++){
        if(b[i]) continue;
        if(!b[i + 1]) dp[i + 1] += dp[i], dp[i + 1] %= MOD;
        if(!b[i + 2]) dp[i + 2] += dp[i], dp[i + 2] %= MOD;
    }
    cout << dp[n] << endl;

    return 0;
}
