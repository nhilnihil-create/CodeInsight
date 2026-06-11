#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, n) for (ll i = 0; i < n; ++i)
#define rREP(i, n) for (ll i = n - 1; i >= 0; --i)
#define FOR(i, a, b) for (ll i = a; i <= b; ++i)
#define rFOR(i, a, b) for (ll i = a; i >= b; --i)
#define aFOR(i, V) for (auto i : V)
#define ALL(vec) vec.begin(), vec.end()
#define rALL(vec) vec.rbegin(), vec.rend()
#define INF 1'000'000'007 // 10^9 + 7
#define MOD 1'000'000'007 // 10^9 + 7
#define lINF 1'000'000'000'000'000'007 // 10^18 + 7
// ------------------------------

int main() {
    int N;
    cin >> N;
    ll a = 1, b = 1, c = 1, d = 1;
    REP(i, N) {
        a = a * 10 % MOD;
        b = b * 9 % MOD;
        c = c * 9 % MOD;
        d = d * 8 % MOD;
    }
    cout << ((a - b - c + d) % MOD + MOD) % MOD << endl;
    return 0;
}