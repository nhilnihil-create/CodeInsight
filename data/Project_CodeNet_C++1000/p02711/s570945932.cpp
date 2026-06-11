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
    bool isOk = false;
    while (N > 0) {
        isOk |= (N % 10) == 7;
        N /= 10;
    }
    PR(isOk ? "Yes" : "No");
    return 0;
}