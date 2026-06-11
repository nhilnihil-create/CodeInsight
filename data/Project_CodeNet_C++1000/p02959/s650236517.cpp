#include <bits/stdc++.h>
using namespace std;
using ll         = long long;
constexpr ll MOD = 1000000007;
#define REP(i, n) for (ll i = 0; i < (n); i++)
#define REP2(i, x, n) for (ll i = x; i < (n); i++)
#define PR(x) cout << (x) << "\n"
#define PS(x) cout << (x) << " "
const long long INF = numeric_limits<long long>::max();
int main() {
    ll N;
    cin >> N;

    vector<ll> monsters(N + 1);
    REP(i, monsters.size()) {
        cin >> monsters[i];
    }

    vector<ll> heros(N);
    REP(i, N) {
        cin >> heros[i];
    }

    ll ans = 0;

    REP(i, N) {
        ll m = min(monsters[i], heros[i]);
        ans += m;
        heros[i] -= m;
        m = min(monsters[i + 1], heros[i]);
        ans += m;
        monsters[i + 1] -= m;
    }

    PR(ans);

    return 0;
}