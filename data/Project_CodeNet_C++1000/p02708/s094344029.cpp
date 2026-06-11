#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define _LL long long
#define rep(i, n) for (_LL i = 0; i < (_LL)(n); i++)
int g_bm = 1000000007;

int modl(_LL a)
{
    a %= g_bm;
    if( a < 0 ) a += g_bm * ( 1 - (a + 1) / g_bm );
    return a;
}

int modadd(_LL a, _LL b)
{
    return modl(a + b);
}

int main()
{
    _LL n, k;
    cin >> n >> k;
    int ans = 0;
    for(_LL l = k; l <= n + 1; l++)
    {
        ans = modadd(ans, (n - l + 1 + n) * l / 2 - (l - 1) * l / 2 + 1);
    }
    cout << ans << endl;

}