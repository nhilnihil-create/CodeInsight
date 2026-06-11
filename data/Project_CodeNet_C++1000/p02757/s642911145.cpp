#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
#define FPEN freopen("in.txt", "r", stdin);
#define debug(...)                                                             \
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
    i64 c[maxn];
    i64 n, p;
    string s;
    void solve() {
        cin >> n >> p >> s;
        i64 a = 0, ans = 0, deg = 1;
        c[0] = 1;
        for (int i = 0; i < n; ++i) {
            a = (a * 10 + s[i] - '0') % p;
            if (deg == 0) {
                if (a == 0)
                    ans += i + 1;
            } else {
                ans += c[a * pw(deg, p - 2) % p];
                c[a * pw(deg, p - 2) % p]++;
            }
            deg = deg * 10 % p;
        }
        cout << ans << '\n';
    }
    i64 pw(i64 a, i64 b) {
        i64 res = 1;
        while (b) {
            if (b & 1ll)
                res = res * a % p;
            a = a * a % p;
            b >>= 1;
        }
        return res;
    }
} NSPACE;
int main() {
    FPEN;
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    NSPACE.solve();
}