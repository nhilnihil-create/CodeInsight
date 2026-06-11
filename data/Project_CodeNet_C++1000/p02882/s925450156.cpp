#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using ii = pair<int, int>;
using vii = vector<ii>;

#define rep(i, n)   for (int i = 0; i < (n); i++)
#define sz(x)       (int)x.size()
#define eb          emplace_back
#define pb          push_back
#define all(x)      x.begin(), x.end()
#define rall(x)     x.rbegin(), x.rend()
#define fi          first
#define se          second

const double pi(acos(-1.0));

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("io\\in.txt", "r", stdin);
    freopen("io\\out.txt", "w", stdout);
#endif

    int a, b, x;
    cin >> a >> b >> x;

    double l = 0, r = 90;
    while (l * (1 + 1e-9) < r) {
        double d = (l + r) / 2;
        double rad = d * pi / 180;

        double v;
        if (b * cos(rad) > a * sin(rad))
             v = a * a * b - a * a * a * tan(rad) +
                 0.5 * a * a * a * tan(rad);
        else v = 0.5 * a * b * b / tan(rad);
        if (x >= v) r = d;
        else l = d;
    }

    cout << setprecision(6) << fixed << l;

    return 0;
}
