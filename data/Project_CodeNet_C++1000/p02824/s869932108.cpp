#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define _LL long long
_LL* mallocint(_LL si)
{
    return (_LL*) malloc(si * sizeof(_LL));
}

_LL* inputint(_LL n)
{
    _LL *ans = mallocint(n);
    for( _LL i = 0; i < n; i++ ) cin >> ans[i];
    return ans;
}


int main()
{
    _LL n, m , v, p;
    cin >> n >> m >> v >> p;
    vector<_LL> a;
    for( _LL i = 0; i < n; i++ ) 
    {
        _LL tmp;
        cin >> tmp;
        a.push_back(tmp);
    }
    sort(a.begin(), a.end());

    if( v < p )
    {
        _LL border = a[n - 1 - (p - 1)];
        for( _LL i = 0; i < n; i++ ) 
        {
            if( a[i] + m >= border )
            {
                cout << n - i;
                return 0;
            }
        }
    }
    else
    {
        _LL allsum = 0;
        for( _LL i = 0; i < n - p + 1; i++ )
        {
            allsum += a[i];
        }
        allsum += m * (v - p + 1);
        for( _LL i = 0; i < n - p + 1; i++ ) 
        {
            _LL border = a[n - 1 - (p - 1)];
            _LL border2 = (allsum - 1) / (n - p + 1 - i) + 1;
//            cout << "i = " << i << " allsum = " << allsum << " border = " << border << endl; 
            if( a[i] + m >= border && a[i] + m >= border2 )
            {
                cout << n - i;
                return 0;
            }
            allsum -= m + a[i];
        }
    }
    cout << p;    

    return 0;
}