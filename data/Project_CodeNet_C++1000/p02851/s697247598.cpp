#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define _LL long long
#define rep(i, n) for(_LL i = 0; i < (_LL)(n); i++)

int modl(_LL a, _LL k)
{
    a %= k;
    if( a < 0 ) a += k * ( 1 - (a + 1) / k );
    return a;
}

int modadd(_LL a, _LL b, _LL k)
{
    return modl(a + b, k);
}

int modminus(_LL a, _LL b, _LL k)
{
    return modl(a - b, k);
}

int main()
{
    _LL n, k;
    cin >> n >> k;
    _LL* a = (_LL*) malloc(n * sizeof(_LL));
    rep(i, n) cin >> a[i];

    map<_LL, _LL> sub;
    _LL sum = 0;
    _LL ans = 0;
    _LL *dl = (_LL*) malloc(n * sizeof(_LL));
    rep(i, n)
    {
        sum = modadd(sum, a[i], k);
        if( i - k >= 0 )
        {
            int rem = i - k;
            sub[dl[rem]]--;
        }

        if(sum == i + 1) ans += 1;
        _LL d = modminus(sum, i + 1, k);
        ans += sub[d];
//        cout << i << ":" << d << " : " << ans << endl;
        sub[d]++;
        dl[i] = d;
    }
    cout << ans << endl;
}