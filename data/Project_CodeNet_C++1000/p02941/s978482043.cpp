#include <bits/stdc++.h>
#define rep(i, x, y) for (int i = x; i <= y; i++)
using namespace std;

typedef long long ll;
typedef pair<ll, int> pii;
const int N = 2e5 + 10;
ll n, a[N], b[N], c[N], tot, k;
int pre[N], nxt[N];
bool mark[N];
priority_queue<pii> q;

bool chk() {
    rep(i, 1, n) if (a[i] != c[i]) return 0;
    return 1;
}

int main() {
    cin >> n;
    rep(i, 1, n) scanf("%lld", &a[i]);
    int cnt = 0;
    rep(i, 1, n) {
        scanf("%lld", &b[i]);
        pre[i] = i - 1, nxt[i] = i + 1;
        if (a[i] != b[i]) q.push(make_pair(b[i], i));
    }
    pre[1] = n, nxt[n] = 1;
    while (q.size()) {
        pii u = q.top(); q.pop();
        int x = u.second;
        if (b[x] == a[x]) continue;
        if (b[x] - b[pre[x]] - b[nxt[x]] < a[x]) { puts("-1"); return 0; }
        ll k = (b[x] - a[x]) / (b[pre[x]] + b[nxt[x]]);
        b[x] = (b[x] - a[x]) % (b[pre[x]] + b[nxt[x]]) + a[x];
        tot += k;
        if (a[x] != b[x]) q.push(make_pair(b[x], x));
    }
    printf("%lld\n", tot);
    return 0;
}
