#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>


#

using namespace std;

#define ll long long

int n;
ll a[2005];

ll f[2005][2005];
int idx[2005];

ll absolute(ll val)
{
    return val < 0LL ? -val : val;
}

bool cmp(int A, int b)
{
    return a[A] > a[b];
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", a + i); idx[i] = i;
    }
    sort(idx + 1, idx + n + 1, cmp);
    for (int i = 0; i < n; i++) {
        ll curactive = a[idx[i+1]];
        ll curpos = idx[i+1];
        for (int l = 0; l <= i; l++) {
            int r = i - l;
            f[i+1][l+1] = max(f[i+1][l+1], f[i][l] + curactive * absolute(curpos - (l + 1)));
            f[i+1][l] = max(f[i+1][l], f[i][l] + curactive * absolute(curpos - (n - r)));
        }
    }
    ll ans = 0;
    for (int i = 0; i <= n; i++) ans = max(ans, f[n][i]);
    printf("%lld", ans);
    return 0;
}
