#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define _LL long long

int* mallocint(int si)
{
    return (int*) malloc(si * sizeof(int));
}

int* inputint(int n)
{
    int *ans = mallocint(n);
    for( int i = 0; i < n; i++ ) cin >> ans[i];
    return ans;
}

_LL _f[100004];

int main()
{
    int n, m;
    cin >> n >> m;
    int *a = inputint(m);
    _f[0] = 1;
    int index = 0;
    if(a[index] == 1 )
    {
        _f[1] = 0;
        index++;
    }
    else
    {
        _f[1] = 1;        
    }
    
    for( int i = 2; i <= n; i++ )
    {
        if( a[index] == i )
        {
            index++;
            _f[i] = 0;
        }
        else
        {
            _f[i] = (_f[i - 2] + _f[i - 1]) % 1000000007;
        }        
    }

    cout << _f[n];
}