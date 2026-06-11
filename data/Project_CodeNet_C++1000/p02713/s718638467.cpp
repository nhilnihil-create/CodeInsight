#include <bits/stdc++.h>
using namespace std;
using ll         = long long;
constexpr ll MOD = 1000000007;
#define REP(i, n) for (ll i = 0; i < (n); i++)
#define REP2(i, x, n) for (ll i = x; i < (n); i++)
#define PR(x) cout << (x) << "\n"
#define PS(x) cout << (x) << " "
const long long INF = numeric_limits<long long>::max();

ll GCD(ll a, ll b) {
    if (a > b) swap(a, b);
    while (b != 0) {
        ll c = b;
        ll d = a % b;
        a    = c;
        b    = d;
    }
    return a;
}

int main() {
    ll K;
    cin >> K;

    ll ans = 0;

    REP2(i, 1, K + 1) {
        REP2(j, 1, K + 1) {
            ll g1 = GCD(i, j);
            REP2(k, 1, K + 1) {
                ans += GCD(g1, k);
            }
        }
    }

    PR(ans);

    return 0;
}