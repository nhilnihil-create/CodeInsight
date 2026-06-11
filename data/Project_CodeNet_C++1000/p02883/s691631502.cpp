#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define _LL long long
#define rep(i, n) for(_LL i = 0; i < (_LL)(n); i++)

_LL sub(pair<_LL,_LL> *c, _LL t, _LL index, _LL goal)
{
    _LL cost = 0;
    rep(i, index)
    {
        if( -c[i].first > goal )
        {
            cost += (-c[i].first - goal - 1) / c[i].second + 1;
        }
    }
    if( cost <= t ) return true;
    return false;
}

int main()
{
    _LL n, k;
    cin >> n >> k;
    _LL *a = new _LL[n];
    _LL *f = new _LL[n];
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> f[i];
    sort(a, a + n);
    sort(f, f + n);
    pair<_LL,_LL> *c = new pair<_LL,_LL>[n];
    rep(i, n) 
    {
        c[i] = make_pair( -a[i] * f[n - 1 - i], f[n - 1 - i]);
    }

    _LL bmax = 0;
    rep(i, n) bmax = max(bmax, -c[i].first);
    _LL bmin = 0;
    while( bmax > bmin )
    {
        _LL half = (bmin + bmax) / 2;
        if( sub(c, k, n, half) )
        {
            bmax = half;
        }
        else
        {
            bmin = half + 1;
        }
//        cout << "[" << bmin << "," << bmax << "]" << endl;
    }
    cout << bmax << endl; 
}