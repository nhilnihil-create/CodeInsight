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
    i64 lcm(i64 a, i64 b) {
        return a * b / __gcd(a, b);
    }
    void solve() {
        i64 n, m;
        cin >> n >> m;
        vector<i64> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        i64 b = 1;
        for (int i = 0; i < n; ++i) {
            b = lcm(b, a[i] / 2);
            if (b > m) {
                cout << 0;
                return;
            }
        }
        for (int i = 0; i < n; ++i) {
            if ((b / (a[i] / 2)) % 2 == 0) {
                cout << 0;
                return;
            }
        }
        cout << 1 + (m - b) / 2 / b << '\n';
    }
} NSPACE;
int main() {
    FPEN;
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    NSPACE.solve();
}