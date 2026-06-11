#include <algorithm>
#include <bitset>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>

using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define reps(i, f, n) for (ll i = (f); i < (n); i++)
#define repv(v) for (auto it = (v).begin(); it != (v).end(); it++)
ll const INF = 1LL << 60;
ll const MAX_N = 510000;
ll const MOD = 1000000007;

int main() {
    double a, b, x;
    cin >> a >> b >> x;

    double S = x / a;
    double ans;

    if (S >= a * b / 2) {
        ans = atan(2 * (a * b - S) / (a * a)) / M_PI * 180.0;
    } else {
        ans = atan((b * b) / (2.0 * S)) / M_PI * 180.0;
    }

    // double theta = (atan((a * a) / (2 * (a * b - S)))) / M_PI * 180.0;
    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}