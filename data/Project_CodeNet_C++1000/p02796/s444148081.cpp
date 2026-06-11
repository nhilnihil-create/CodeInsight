#include <bits/stdc++.h>
using namespace std;
using ll         = long long;
constexpr ll MOD = 1000000007;
#define REP(i, n) for (ll i = 0; i < (n); i++)
#define REP2(i, x, n) for (ll i = x; i < (n); i++)
const long long INF = numeric_limits<long long>::max();
template <class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
int main() {
    ll N;
    cin >> N;
    vector<pair<ll, ll>> robots(N);
    for (ll i = 0; i < N; ++i) {
        ll a, b;
        cin >> a >> b;
        robots[i].second = a - b;
        robots[i].first  = a + b;
    }

    sort(robots.begin(), robots.end(), [](const auto& a, const auto& b) { return a.first < b.first; });

    ll next  = robots[0].first;
    ll count = 1;
    for (ll i = 1; i < robots.size(); ++i) {
        if (next <= robots[i].second) {
            count++;
            next = robots[i].first;
        }
    }
#ifdef SOURCE_TEST
    for (auto& r : robots) {
        cout << r.first << "," << r.second << endl;
    }

#endif

    cout << count << endl;
    return 0;
}
