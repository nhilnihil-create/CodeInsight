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
    map<ll, ll> values;
    REP(i, N) {
        ll n;
        cin >> n;
        values[n]++;
    }

    bool isOk = true;
    for (const auto& v : values) {
        isOk &= v.second == 1;
    }

    PR(isOk ? "YES" : "NO");
    return 0;
}