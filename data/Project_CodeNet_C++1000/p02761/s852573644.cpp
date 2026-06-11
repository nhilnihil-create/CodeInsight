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
    ll N, M;
    cin >> N >> M;

    vector<ll> digits(N, -1);
    bool isOk = true;
    REP(i, M) {
        ll s, c;
        cin >> s >> c;
        if (digits[s - 1] != -1 && digits[s - 1] != c) {
            isOk = false;
            break;
        }

        digits[s - 1] = c;
    }
    if (digits[0] == 0 && N != 1) {
        isOk = false;
    }
    if (!isOk) {
        PR(-1);
    } else {
        ll ans = 0;
        REP(i, N) {
            ans *= 10;
            if (digits[i] == -1) {
                if (i == 0 && N != 1) {
                    ans += 1;
                } else {
                    ans += 0;
                }
            } else {
                ans += digits[i];
            }
        }
        PR(ans);
    }

    return 0;
}