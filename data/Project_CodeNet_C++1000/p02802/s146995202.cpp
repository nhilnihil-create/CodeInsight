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
    ll N, M;
    cin >> N >> M;

    map<ll, pair<ll, ll>> answers;

    REP(i, M) {
        ll n;
        string s;
        cin >> n >> s;
        if (s == "WA") {
            if (answers[n].second == 0) {
                answers[n].first++;
            }
        } else {
            answers[n].second = 1;
        }
    }
    ll a = 0;
    ll b = 0;
    for (const auto& m : answers) {
#ifdef SOURCE_TEST
        PS(m.first);
        PS(m.second.first);
        PR(m.second.second);
#endif
        if (m.second.second > 0) {
            a += m.second.second;
            b += m.second.first;
        }
    }

    PS(a);
    PR(b);

    return 0;
}