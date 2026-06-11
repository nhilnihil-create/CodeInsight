#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define _LL long long
int main()
{
    _LL  n, a, b;
    cin >> n >> a >> b;
    if( (b - a) % 2 == 0 )
    {
        cout << (b - a) / 2;
    }
    else
    {
        if ( a - 1 < n - b )
        {
            cout << a + ( b - a  - 1) / 2;
        }
        else
        {
            cout << (n - b + 1) + ( b - a - 1) / 2;
        }
    }
    
    return 0;
}