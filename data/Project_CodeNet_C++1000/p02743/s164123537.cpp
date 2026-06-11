#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define _LL long long

bool getAns(_LL a, _LL b, _LL c)
{
    if( a + b >= c ) return false;
    _LL r = c - a- b;
    return 4 * a * b < r * r;
}

int main()
{
    _LL a, b, c;
    cin >> a >> b >> c;
    if( getAns(a, b, c) )
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
    
}