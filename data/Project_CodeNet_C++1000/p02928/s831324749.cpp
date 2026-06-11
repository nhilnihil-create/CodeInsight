#include<bits/stdc++.h>
#define int long long

using namespace std;

const int   N      =    2005    ;
const int   mod    =    1e9 + 7 ;

int n, k, a[N], sA[N], sB[N], bit[N];

int get(int id) {
    int ret = 0;
    for (; id; id -= id & -id)
        ret += bit[id];
    return ret;
}

void upd(int id) {
    for (; id < N; id += id & -id)
        bit[id] ++;
}

signed main() {
    //freopen("in.inp", "r", stdin);
    //freopen("ou.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    int ans = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++) {
        upd(a[i]);
        sA[i] = get(a[i] - 1);
    }
    memset(bit, 0, sizeof bit);
    for (int i = n; i >= 1; i--) {
        upd(a[i]);
        sB[i] = get(a[i] - 1);
    }
    for (int i = 1; i <= n; i++) {
        int mulA = ((k * (k - 1) / 2) % mod );
        int mulB = ((k * (k + 1) / 2) % mod );
        ans += mulA * sA[i] % mod; ans %= mod;
        ans += mulB * sB[i] % mod; ans %= mod;
    }

    cout << ans;
}
