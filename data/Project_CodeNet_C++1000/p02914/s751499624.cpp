#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;
const int Maxb = 60;

int n;
ll a[Maxn];
ll my[Maxb];
ll res;

void Write(ll num)
{
    for (int i = Maxb - 1; i >= 0; i--)
        if (num & 1ll << ll(i))
            if (my[i] == 0) { my[i] = num; break; }
            else num ^= my[i];
}

ll Get()
{
    ll res = 0;
    for (int i = Maxb - 1; i >= 0; i--)
        if (!(res & 1ll << ll(i)))
            res ^= my[i];
    return res;
}

int main()
{
    ll tot = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        tot ^= a[i];
    }
    res = tot;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < Maxb; j++)
            if (bool(a[i] & 1ll << ll(j)) && bool(tot & 1ll << ll(j)))
                a[i] ^= 1ll << ll(j);
        Write(a[i]);
    }
    res += 2ll * Get();
    cout << res << endl;
    return 0;
}
