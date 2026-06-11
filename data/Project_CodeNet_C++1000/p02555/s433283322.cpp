#include <bits/stdc++.h>
#ifdef local
#define debug(a...) qqbx(#a, a)
template <typename H, typename ...T> void qqbx(const char *s, const H &h, T&&...a) {
    for(; *s && *s != ','; ++s) if(*s != ' ') std::cerr<<*s;
    std::cerr<<" = "<<h<<(sizeof...(T) ? ", " : "\n");
    if constexpr(sizeof...(T)) qqbx(++s, a...);
}
#else
#define debug(...) ((void)0)
#endif // local
#define pb emplace_back
#define all(v) begin(v),end(v)

using namespace std;
const int MOD = 1000000007, N = 2025;
int dp[N][N], pre[N];
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    dp[0][0] = 1;
    int ans = 0;
    for(int i = 1; i < N; i++) {
        pre[0] = dp[i-1][0];
        for(int w = 1; w <= n; w++) pre[w] = (pre[w-1] + dp[i-1][w]) % MOD;
        for(int w = 3; w <= n; w++) dp[i][w] = pre[w-3];
        ans = (ans + dp[i][n]) % MOD;
    }
    cout << ans << '\n';
}
