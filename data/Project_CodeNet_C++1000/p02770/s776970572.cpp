#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define _LL long long
#define rep(i, n) for (_LL i = 0; i < (_LL)(n); i++)

int main()
{
    _LL k, q;
    cin >> k >> q;
    _LL *d = new _LL[k];
    _LL *td = new _LL[k];
    rep(i, k) cin >> d[i];
    rep(t, q)
    {
        _LL n, x, m;
        cin >> n >> x >> m;
        rep(i, k) td[i] = d[i] % m;
        _LL ln = (n - 1) / k;
        _LL lm = (n - 1) % k;
        _LL dsum = 0;
        _LL count = 0;
        rep(i, k)
        {
            dsum += td[i];
            if( td[i] != 0 ) count++;
        }
        dsum *= ln;
        count *= ln;
        rep(i, lm) 
        {
            dsum += td[i];
            if( td[i] != 0 ) count++;
        }
        dsum += x % m;
        cout << count - dsum / m << endl;
    }
}