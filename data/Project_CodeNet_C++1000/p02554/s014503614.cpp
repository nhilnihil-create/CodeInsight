#include <bits/stdc++.h>
using namespace std;
using ll         = long long;
constexpr ll MOD = 1000000007;
#define REP(i, n) for (ll i = 0; i < (n); i++)
#define REP2(i, x, n) for (ll i = x; i < (n); i++)
#define PR(x) cout << (x) << "\n"
#define PS(x) cout << (x) << " "
#define PRYES(x) PR((x) ? "Yes" : "No")
const long long INF = numeric_limits<long long>::max();
// SourceTest用出力マクロ
#ifdef SOURCE_TEST
#define SPR(x) PR(x)
#define SPS(x) PS(x)
#else
#define SPR(x) \
    {}
#define SPS(x) \
    {}
#endif
int main() {
    ll N;
    cin >> N;

    ll sum  = 1;
    ll sum2 = 1;  // 0or9以外
    ll sum3 = 1;  // 0でも9でもない
    REP(i, N) {
        sum *= 10;
        sum %= MOD;
        sum2 *= 9;
        sum2 %= MOD;
        sum3 *= 8;
        sum3 %= MOD;
    }

    ll ans = sum;
    ans += sum3;
    ans %= MOD;
    ans -= sum2 * 2;
    ans %= MOD;
    if (ans < 0) {
        ans += MOD;
    }
    PR(ans);

    return 0;
}