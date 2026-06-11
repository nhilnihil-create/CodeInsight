#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define _LL long long

_LL* mallocint(int si)
{
    return (_LL*) malloc(si * sizeof(_LL));
}

_LL* inputint(int n)
{
    _LL *ans = mallocint(n);
    for( int i = 0; i < n; i++ ) cin >> ans[i];
    return ans;
}

int main()
{
    int x, y, a, b, c;
    cin >> x >> y >> a >> b >>c;
    _LL *p = inputint(a);
    _LL *q = inputint(b);
    _LL *r = inputint(c);
    sort(p, p + a);
    sort(q, q + b);
    sort(r, r + c);
    int xindex = a - x;
    int yindex = b - y;
    int rindex = c - 1;
    while( ((xindex < a && r[rindex] > p[xindex]) ||  (yindex < b && r[rindex] > q[yindex])) && rindex >= 0 )
    {
        if( yindex >= b || p[xindex] < q[yindex] )
        {
            xindex++;
        }
        else
        {
            yindex++;
        }
        rindex--;
    }

    _LL ans = 0;
    for( int i = xindex; i < a; i++ ) ans += p[i];
    for( int i = yindex; i < b; i++ ) ans += q[i];
    for( int i = rindex + 1; i < c; i++ ) ans += r[i];
    cout << ans;
}