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
const int MOD = 1000000007;
int64_t modpow(int64_t e, int64_t p) {
    int64_t r = 1;
    while(p) {
        if(p&1) r = r*e%MOD;
        e = e*e%MOD;
        p>>=1;
    }
    return r;
}
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    cout << (modpow(10, n) - modpow(9, n) * 2 % MOD + modpow(8, n) % MOD + MOD) % MOD << '\n';
}
