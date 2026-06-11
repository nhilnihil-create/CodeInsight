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
    int n, d, a;
    pi H[maxn];
    i64 sum[maxn];
    void solve() {
        cin >> n >> d >> a;
        for (int i = 0; i < n; ++i) cin >> H[i].first >> H[i].second;
        sort(H, H + n);
        i64 ans = 0;
        for (int i = 0; i < n; ++i) {
            if (i)
                sum[i] += sum[i - 1];
            if (sum[i] >= H[i].second)
                continue;
            int id = lower_bound(H, H + n, make_pair(H[i].first + 2 * d, 0)) - H;
            if (id == n || H[id].first > H[i].first + 2 * d)
                id--;
            i64 bm = (H[i].second - sum[i] + a - 1) / a;
            sum[i] += bm * a;
            sum[id + 1] -= bm * a;
            ans += bm;
        }
        cout << ans << '\n';
    }
} NSPACE;
int main() {
    FPEN;
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    NSPACE.solve();
}