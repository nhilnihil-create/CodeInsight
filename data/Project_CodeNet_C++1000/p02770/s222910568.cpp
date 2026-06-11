#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 5005;

int k, q;
ll d[Maxn], D[Maxn];

ll getSmall(ll a, ll b, ll x, ll mod)
{
    if (x == 0) return -1;

}

int main()
{
    scanf("%d %d", &k, &q);
    for (int i = 1; i <= k; i++)
        scanf("%lld", &d[i]);
    while (q--) {
        ll n, x, mod; scanf("%lld %lld %lld", &n, &x, &mod);
        ll zers = 0, sum = 0;
        D[0] = x % mod;
        for (int i = 1; i <= k; i++) {
            D[i] = D[i - 1] + d[i] % mod;
            if (d[i] % mod == 0) zers++;
            sum += d[i] % mod;
        }
        ll tims = (n - 1) / k;
        int lst = (n - 1) % k;
        ll lef = D[0];
        ll rig = tims * sum + D[lst];
        ll all = rig / mod - (lef > 0? (lef - 1) / mod: 0);
        all += tims * ll(zers);
        for (int i = 1; i <= lst; i++)
            all += d[i] % mod == 0;
        ll res = n - 1 - all;
        cout << res << endl;
    }
    return 0;
}
