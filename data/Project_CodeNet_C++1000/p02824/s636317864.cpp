#include <bits/stdc++.h>

#define ub(b,val) upper_bound(b+1,b+n+1,val)-b
#define ll long long

using namespace std;

const int N = 1e5 + 123, MAXN = 1e9;

ll n, m, v, p;

ll a[N], b[N], ans, c[N];

bool check (int in) {
    ll k = 0, id = (n - p + 1);
    if (b[in] + m < b[id])return 0;
    k += (p - 1) * 1ll * m + (in - 1) * 1ll  * m;
    for (int i = in;i <= id;i ++) {
        k += m + b[in] - b[i];
    }
    return (k >= m * v);
}

int main () {
    ios_base::sync_with_stdio (0), cin.tie (0), cout.tie (0);
    cin >> n >> m >> v >> p;
    for (int i = 1;i <= n;i ++) {
        cin >> a[i];
        b[i] = a[i];
    }sort (b + 1, b + n + 1);
    int l = 1, r = n, id = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check (mid)) {
            r = mid - 1;
            id = mid;
        }else {
            l = mid + 1;
        }
    }
    cout << (id == -1 ? 0 : (n - id + 1));
}
