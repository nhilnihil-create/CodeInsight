#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL
        #include "debug.h"
        #define input freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        #else
        #define debug(...) 4
        #define input ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif

using ll = long long;
const int N = 2e5 + 5;
const int mod = 998244353;
int dp[3005][3005];
inline int power(int x, int y, int res = 1) {
    for (; y; y >>= 1, x = 1ll * x * x % mod) {
        if (y & 1) { res = 1ll * res * x % mod; }
    } return res;
}

int main() {
    input;
    int n, s;
    cin >> n >> s;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    dp[0][0] = power(2, n);
    int inv2 = power(2, mod - 2);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= s; j++) {
            dp[i + 1][j] += dp[i][j];
            dp[i + 1][j] %= mod;
            if(a[i] + j <= s) {
                dp[i + 1][j + a[i]] += (1LL * dp[i][j] * inv2) % mod;
                dp[i + 1][j + a[i]] %= mod;
            }
        }
    }
    cout << dp[n][s];
}
