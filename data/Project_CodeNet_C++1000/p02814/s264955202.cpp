#include <bits/stdc++.h>
#include <iostream>
using namespace std;


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

#define _LL long long

_LL gcd(int a, int b)
{
    if( b == 0 ) return a;
    return gcd( b, a % b );
}

_LL lcm(int a, int b)
{
    return ((_LL)a) * b / gcd(a, b);
}

_LL lcm(int *a, int n)
{
    _LL ans;
    ans = a[0];
    for( int i = 1; i < n; i++ )
    {
        ans = lcm(ans, a[i]);
    }
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int *a = inputint(n);
    for( int i = 0; i < n; i++ ) a[i] /= 2;

    _LL slcm = lcm(a, n);

//    cout << slcm << endl;

    for( int i = 0; i < n; i++ )
    {
        if( (slcm / a[i]) % 2 == 0 ) 
        {
            cout << 0;
            return 0;
        }
    }

    _LL t = m / slcm;
    cout << (t + 1) / 2;
}