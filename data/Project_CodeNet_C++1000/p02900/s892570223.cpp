#include <bits/stdc++.h>
#include <iostream>
#include <ctime>
using namespace std;
#define _LL long long
#define rep(i, n) for (_LL i = 0; i < (_LL)(n); i++)
#define vecrep(itr, v) for (auto itr = (v).begin(); itr != (v).end(); itr++)

_LL kouyaku(_LL a, _LL b)
{
    if( b == 0 ) return a;
    if( a == 1 || b == 1 ) return 1;
    if( b > a ) return kouyaku(b, a);
    return kouyaku(b, a % b);
}

void bunkai(vector<pair<_LL, _LL>> &e, _LL n)
{
    for( _LL i = 2; i * i <= n; i++ )
    {
        if( n % i != 0 ) continue;
        int c = 0;
        while( n % i == 0 ) { n /= i; c++; }
        e.emplace_back(i, c);
    }
    if( n != 1) e.emplace_back(n, 1);
}

int main()
{
    _LL a, b; cin >> a >> b;
    _LL n = kouyaku(a, b);
    vector<pair<_LL, _LL>> e;
    bunkai(e, n);
    cout << e.size() + 1;
    return 0;    
}