#include <bits/stdc++.h>
#define rep(i, x, y) for (int i = x; i <= y; i++)
using namespace std;

const int N = 3e5 + 10;
typedef long long ll;
ll n, x, a[N], K, cnt[N], sum[N], ans[N];

bool chk(ll k, ll x) { return sum[x] >= k * x; }

int main() {
    cin >> n;
    rep(i, 1, n) cin >> x, ++sum[++cnt[x]];
    rep(i, 1, n) sum[i] += sum[i - 1];
    ll now = 0;
    for (int k = n; k >= 1; k--) {
        while (now < n && chk(k, now + 1)) ++now;
        ans[k] = now;
    }
    rep(i, 1, n) printf("%lld\n", ans[i]);
    return 0;
}
