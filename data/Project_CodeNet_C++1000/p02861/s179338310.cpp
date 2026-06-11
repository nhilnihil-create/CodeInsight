#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e18;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; i >= a; i--)
#define int ll
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int len(pint i, pint j) {
    return (i.first - j.first) * (i.first - j.first) + (i.second - j.second) * (i.second - j.second);
}

signed main() {
    int n;
    cin >> n;
    int x[n], y[n];
    pint p[n];
    rep(i, 0, n) cin >> p[i].first >> p[i].second;
    sort(p, p + n);
    double sum = 0;
    do {
        rep(i, 1, n) sum += sqrt(len(p[i], p[i - 1]));

    } while (next_permutation(p, p + n));
    rep(i, 1, n + 1) sum /= i;
    cout << fixed << setprecision(10) << sum << "\n";
}