#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define _LL long long

_LL getAns(_LL h, _LL w)
{
    _LL ans;
    if( h == 1 || w == 1 ) return 1;
    ans = w * (h / 2);
    if( h % 2 == 1 ) ans += ( w + 1 ) / 2;
    return ans;
}

int main()
{
    _LL h, w;
    cin >> h >> w;

    cout << getAns(h, w);
}