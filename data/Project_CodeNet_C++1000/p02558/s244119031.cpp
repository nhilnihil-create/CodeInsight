#include <bits/stdc++.h>

#include <atcoder/all>
#define For(i, a, b) for (int(i) = (int)(a); (i) < (int)(b); ++(i))
#define rFor(i, a, b) for (int(i) = (int)(a)-1; (i) >= (int)(b); --(i))
#define rep(i, n) For((i), 0, (n))
#define rrep(i, n) rFor((i), (n), 0)
#define fi first
#define se second
using namespace std;
using namespace atcoder;
typedef long long lint;
typedef unsigned long long ulint;
typedef pair<int, int> pii;
typedef pair<lint, lint> pll;
template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
bool chmin(T &a, const T &b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
T div_floor(T a, T b) {
    if (b < 0) a *= -1, b *= -1;
    return a >= 0 ? a / b : (a + 1) / b - 1;
}
template <class T>
T div_ceil(T a, T b) {
    if (b < 0) a *= -1, b *= -1;
    return a > 0 ? (a - 1) / b + 1 : a / b;
}

constexpr lint mod = 1000000007;
constexpr lint INF = mod * mod;
constexpr int MAX = 200010;

int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    dsu uf(n);
    rep(_, q) {
        int t, u, v;
        scanf("%d%d%d", &t, &u, &v);
        if (t == 0)
            uf.merge(u, v);
        else
            printf("%d\n", uf.same(u, v));
    }
}