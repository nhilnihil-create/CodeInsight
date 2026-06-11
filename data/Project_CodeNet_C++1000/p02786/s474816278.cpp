#include <bits/stdc++.h>
#include <iostream>
#include <ctime>
using namespace std;
#define _LL long long
#define rep(i, n) for (_LL i = 0; i < (_LL)(n); i++)
#define vecrep(itr, v) for (auto itr = (v).begin(); itr != (v).end(); itr++)

_LL ans(_LL h)
{
    if( h == 1 ) return 1;
    return 2 * ans( h / 2) + 1;
}

int main()
{
    _LL h; cin >> h;
    cout << ans(h);    
}