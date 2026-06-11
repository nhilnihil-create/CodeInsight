#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
#define ld long double
#define ll long long
#define mod 1000000007
#define IINF INT_MAX
#define INF 1LL << 30


int main() {
    int n, m; cin >> n >> m;
    V<int> b(n + 1);
    for(int i = 0; i < m; i++){
        int x; cin >> x;
        b[x] = 1;
    }

    // 前からdp
    V<int> dp(n + 10);
    dp[0] = 1;
    for(int i = 0; i <= n - 1; i++){
        if(b[i]) continue;
        if(!b[i + 1]) (dp[i + 1] += dp[i]) %= mod;
        if(!b[i + 2]) (dp[i + 2] += dp[i]) %= mod;
    }
    cout << dp[n] << endl;
    return 0;
}
