#include <bits/stdc++.h>
using namespace std;

#define int         long long
#define endl        "\n"
#define P           pair<int, int>

const int mod = 998244353;

inline int add(int x, int y) { int res = x + y; if(res >= mod) res -= mod; return res; }
inline int sub(int x, int y) { int res = x - y; if(res < 0) res += mod; return res; }
inline int mul(int x, int y) { int res = (x % mod * y % mod) % mod; return res; }

int modpow(int a, int b) {
    if(a == 0 || a == 1 || b == 1) return a;
    int res = 1;
    while(b) {
        if(b % 2) res = mul(res, a);
        b /= 2;
        a = mul(a, a);
    }
    return res;
}

const int N = 3003;
int pw[N];
const int MI2 = modpow(2, mod - 2);
int dp[N][N];
int n, s;
int a[N];

void solve() {
    cin >> n >> s;
    for(int i=1; i<=n; i++) cin >> a[i];
    memset(dp, 0, sizeof dp);
    dp[0][0] = pw[n];
    for(int i=1; i<=n; i++) {
        for(int j=0; j<=s; j++) {
            dp[i][j] = add(dp[i][j], dp[i - 1][j]);
            if(j - a[i] >= 0) dp[i][j] = add(dp[i][j], mul(MI2, dp[i-1][j - a[i]]));
        }   
    }
    cout << dp[n][s] << endl;
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(12);

    int T = 1;
    // cin >> T;
    pw[0] = 1;
    for(int i=1; i<N; i++) pw[i] = mul(2, pw[i-1]);
    for(int i=1; i<=T; i++) {
        solve();
    }
    return 0;
}