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
const int MOD = 1000000007, N = 2025, inf = 2e9;
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    int mn[2] = {inf, inf};
    int mx[2] = {-inf, -inf};
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        mn[0] = min(mn[0], x+y);
        mn[1] = min(mn[1], x-y);
        mx[0] = max(mx[0], x+y);
        mx[1] = max(mx[1], x-y);
    }
    cout << max(mx[0]-mn[0], mx[1]-mn[1]) << '\n';
}
