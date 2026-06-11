#include <bits/stdc++.h>
#define rep(i, x, y) for (int i = x; i <= y; i++)
using namespace std;

const int N = 1e5 + 10;
typedef long long ll;
int n, q[65];
ll a[N], sum, tot, p[65];

void insert(ll x) {
    rep(i, 1, tot) {
        if (!(x & (1ll << q[i]))) continue;
        if (!p[i]) {
            p[i] = x; break;
        }
        x ^= p[i];
    }
}

int main() {
    cin >> n;
    rep(i, 1, n) {
        scanf("%lld", &a[i]);
        sum ^= a[i];
    }
    for (int i = 60; i >= 0; i--) {
        if (!((1ll << i) & sum)) q[++tot] = i;
    }
    rep(i, 1, n) insert(a[i]);
    ll res = 0;
    rep(i, 1, tot) {
        if (!(res & (1ll << q[i]))) res ^= p[i];
    }
    printf("%lld\n", res + (sum ^ res));
    return 0;
}
