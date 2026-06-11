#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define _LL long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    _LL n, r;
    cin >> n >> r;
    if( n < 10 )
    {
        cout << (r + 100 * (10 - n) );
    }
    else
    {
        cout << r;
    }
}