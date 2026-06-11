#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
#define FPEN freopen("in.txt", "r", stdin);
#define TEST(...)                                                              \
    { printf("! "), printf(__VA_ARGS__); }
#else
#define TEST(...)
#define FPEN
#endif
const int maxn = 200009;
typedef long long i64;
typedef pair<i64, i64> pi64;
typedef pair<int, int> pi;
const i64 MOD = 1e9 + 7;
class {
  public:
    i64 cnt[maxn], pwN[maxn], n, k;
    i64 pw(i64 a, i64 b) {
        i64 res = 1;
        while (b) {
            if (b & 1)
                res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }
    void solve() {
        cin >> n >> k;
        for (int i = 1; i <= k; ++i)
            pwN[i] = pw(i, n);
        for (int i = 1; i <= k; ++i)
            cnt[i] = i;
        i64 ans = 0;
        for (int i = 1; i <= k; ++i) {
            (ans += pwN[k / i] * cnt[i] % MOD) %= MOD;
            i64 count = cnt[i];
            for (int j = i; j <= k; j += i)
                cnt[j] -= count;
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