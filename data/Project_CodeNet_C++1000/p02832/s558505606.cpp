#include <bits/stdc++.h>
#include <iostream>
using namespace std;


#define _LL long long

_LL* mallocint(int si)
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
    _LL n;
    cin >> n;
    _LL *a = inputint(n);

    _LL index = 1;
    for( _LL i = 0; i < n; i++ )
    {
        if( a[i] == index ) index++;
    }
    if( index == 1 )
    {
        cout << -1;
        return 0;
    }
    cout << n - (index - 1) ;
}