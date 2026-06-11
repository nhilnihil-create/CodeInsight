#include <bits/stdc++.h>
#define For(i, a, b) for (int(i) = (int)(a); (i) < (int)(b); ++(i))
#define rFor(i, a, b) for (int(i) = (int)(a)-1; (i) >= (int)(b); --(i))
#define rep(i, n) For((i), 0, (n))
#define rrep(i, n) rFor((i), (n), 0)
#define fi first
#define se second
using namespace std;
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

int n;
vector<pii> G[MAX];  // (id, to)
int col[MAX];

void dfs(int v, int pv, int pc) {
    int cur = 1;
    for (auto &e : G[v])
        if (e.se != pv) {
            if (cur == pc) ++cur;
            col[e.fi] = cur;
            dfs(e.se, v, cur);
            ++cur;
        }
}

int main() {
    scanf("%d", &n);
    rep(i, n - 1) {
        int a, b;
        scanf("%d%d", &a, &b);
        --a;
        --b;
        G[a].emplace_back(i, b);
        G[b].emplace_back(i, a);
    }
    dfs(0, -1, -1);
    printf("%d\n", *max_element(col, col + n - 1));
    rep(i, n - 1) printf("%d\n", col[i]);
}