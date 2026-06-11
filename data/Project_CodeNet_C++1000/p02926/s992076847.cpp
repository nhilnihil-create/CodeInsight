#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for(int(i) = 0; (i) < (n); (i)++)
#define FOR(i, m, n) for(int(i) = (m); (i) < (n); (i)++)
#define All(v) (v).begin(), (v).end()
#define pb push_back
#define MP(a, b) make_pair((a), (b))
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;
const int MOD = 1e9 + 7;

int main() {
    int N;
    cin >> N;
    using pld = pair<long double, long double>;
    vector<pld> engines(N);
    rep(i, N) { cin >> engines[i].first >> engines[i].second; }
    sort(All(engines), [](const auto &p1, const auto &p2) {
        return atan2l(p1.second, p1.first) < atan2l(p2.second, p2.first);
    });
    for(int i = 0; i < N; i++) {
        engines.pb(engines[i]);
    }
    long double res = 0;
    for(int l = 0; l < N; l++) {
        for(int r = l; r - l < N; r++) {
            long double dx = 0, dy = 0;
            for(int i = l; i <= r; i++) {
                dx += engines[i].first, dy += engines[i].second;
            }
            res = max(res, sqrt(dx * dx + dy * dy));
        }
    }
    cout << fixed << setprecision(20) << res << endl;
    return 0;
}