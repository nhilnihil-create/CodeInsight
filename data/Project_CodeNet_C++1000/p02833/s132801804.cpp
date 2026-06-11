#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define _LL long long

int main()
{
    _LL n;
    cin >> n;
    _LL a = 10;
    _LL ans = 0;
    if( n % 2 == 1 )
    {
        cout << 0;
        return 0;
    }
    while( a <= n )
    {
        ans += ( n / a );
        a *= 5;
    }
    cout << ans;
    return 0;
}
