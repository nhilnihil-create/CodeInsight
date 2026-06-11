#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <cmath>
#include <iomanip>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define REP(i, n) for (int i = 0; i < (n); i++)
#define RREP(i, n) for (int i = (n) - 1; i >= 0; i--)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define RFOR(i, a, b) for (int i = (a); i > (b); i--)
#define ALL(a) (a).begin(), (a).end()

int main() {
    int N;
    cin >> N;

    pii xy[100];
    REP(i, N) {
        int x, y;
        cin >> x >> y;
        xy[i] = {x, y};
    }
    sort(xy, xy + N, [](const pii &p1, const pii&p2) { return atan2(p1.second, p1.first) < atan2(p2.second, p2.first); });


    double ans = 0;
    REP(i, N) {
        ll x = 0, y = 0, r = i;
        REP(j, N) {
            x += xy[r].first;
            y += xy[r].second;
            ans = max(ans, sqrt(x * x + y * y));
            r = (r + 1) % N;
        }
    }
    cout << setprecision(30) << ans << endl;
    return 0;
}