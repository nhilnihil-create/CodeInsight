#include <bits/stdc++.h>
#define pb          emplace_back
#define ll          long long
#define fi          first
#define se          second
#define mp          make_pair

using namespace std;

typedef pair<int, int> pii;
const int N = 102;
const int logN = 17;

pii p[N], cur;
int n;
ll res = 0;

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
        cur = p[i]; res = max(res, 1ll * cur.fi * cur.fi + 1ll * cur.se * cur.se);
        for(int j = (i < n? i + 1: 1); j != i; j = (j < n? j + 1: 1)) {
            cur.fi += p[j].fi; cur.se += p[j].se;
            res = max(res, 1ll * cur.fi * cur.fi + 1ll * cur.se * cur.se);
        }
    }
    cout << fixed << setprecision(11);
    cout << sqrt((long double)res);
}
