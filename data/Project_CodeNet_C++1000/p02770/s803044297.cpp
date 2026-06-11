#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
#define FPEN freopen("in.txt", "r", stdin);
#define debug(...) \
    { cerr << "# " << __VA_ARGS__ << "\n"; }
#else
#define debug(...)
#define FPEN
#endif
const int maxn = 200009;
typedef long long i64;
typedef pair<i64, i64> pi64;
typedef pair<int, int> pi;
const i64 MOD = 119 << 23 | 1;
class {
   public:
    i64 d[5555], dd[5555];
    void solve() {
        int k, q;
        cin >> k >> q;
        for (int i = 0; i < k; ++i) cin >> dd[i];
        while (q--) {
            i64 n, x, m;
            cin >> n >> x >> m;
            i64 ans = n - 1;
            i64 c = (n - 1) / k, cc = (n - 1) % k;
            i64 add = 0;
            for (int i = 0; i < k; ++i) {
                d[i] = dd[i] % m;
                if (d[i] == 0)
                    ans -= c;
                if (d[i] == 0 && i + 1 <= cc)
                    ans--;
                if (i + 1 <= cc)
                    add += d[i] * c + d[i];
                else
                    add += d[i] * c;
            }
            i64 y = x + add;
            i64 cntR = y / m + 1, cntL;
            if (x == 0)
                cntL = 0;
            else
                cntL = (x - 1) / m + 1;
            ans -= cntR - cntL;
            if (x % m == 0)
                ans++;
            cout << ans << '\n';
        }
    }
} NSPACE;
int main() {
    FPEN;
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    NSPACE.solve();
}