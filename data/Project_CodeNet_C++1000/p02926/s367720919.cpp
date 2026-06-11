#include <bits/stdc++.h>
#define pb          emplace_back
#define ll          long long
#define fi          first
#define se          second
#define mp          make_pair
#define int         int64_t

using namespace std;

typedef pair<int, int> pii;
const int N = 102;
const int logN = 17;

pii p[N], cur, res;
int n;

pii operator+(const pii& x, const pii& y) {
    return mp(x.fi + y.fi, x.se + y.se);
}

pii Max(const pii& x, const pii& y) {
    if(x.fi * x.fi + x.se * x.se > y.fi * y.fi + y.se * y.se) return x;
    return y;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    #define Task        "test"
    if(fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> p[i].fi >> p[i].se;
    sort(p + 1, p + n + 1, [](const pii& x, const pii& y) {
            return atan2(x.fi, x.se) < atan2(y.fi, y.se);
         });
    for(int i = 1; i <= n; ++i) {
        cur = p[i]; res = Max(res, cur);
        for(int j = i % n + 1; j != i; j = j % n + 1) {
            cur = cur + p[j];
            res = Max(res, cur);
        }
    }
    cout << fixed << setprecision(16);
    cout << sqrt((long double)(res.fi * res.fi + res.se * res.se));
}
