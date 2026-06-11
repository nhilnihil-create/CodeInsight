#include <bits/stdc++.h>

#include <atcoder/all>
typedef long long ll;
#define rep(i, n) for (ll i = 0, i##_len = (n); i < i##_len; ++i)
#define reps(i, n) for (ll i = 1, i##_len = (n); i <= i##_len; ++i)
#define rrep(i, n) for (ll i = ((ll)(n)-1); i >= 0; --i)
#define rreps(i, n) for (ll i = ((ll)(n)); i > 0; --i)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define repc2(i, s, n) for (ll i = (s); i <= (ll)(n); i++)
#define inf 2e9
#define linf 9000000000000000000ll
#define all(v) v.begin(), v.end()
using namespace std;
using namespace atcoder;

int n, q;

int main() {
    scanf("%d%d", &n, &q);
    fenwick_tree<ll> bit(n);
    rep(i, n) {
        ll a;
        scanf("%lld", &a);
        bit.add(i, a);
    }
    rep(i, q) {
        int c, a, b;
        scanf("%d%d%d", &c, &a, &b);
        if (c == 0) {
            bit.add(a, b);
        } else {
            printf("%lld\n", bit.sum(a, b));
        }
    }
    return 0;
}