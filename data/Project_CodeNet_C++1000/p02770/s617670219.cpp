#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1e18

int main() {
    int k, q;
    cin >> k >> q;
    vector<ll> d0(k);
    for (int i = 0; i < k; i++) cin >> d0[i];

    for (int i = 0; i < q; i++) {
        ll ans, c0 = 0, c1 = 0;
        vector<ll> d = d0, c(k);
        ll n, x, m, ah, at;
        cin >> n >> x >> m;

        ans = n - 1;
        ah = at = x;
        for (int j = 0; j < k; j++) {
            d[j] %= m;
            c[j] = (n - 2) / k + (j <= (n - 2) % k);
            if (d[j] == 0) c0 += c[j];
            at = at + d[j] * c[j];
        }
        c1 = at / m - ah / m;
        ans -= (c0 + c1);
        cout << ans << endl;
    }
    return 0;
}