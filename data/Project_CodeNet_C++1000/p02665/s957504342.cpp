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

int main()
{
    int n;

    cin >> n;
    int *a = inputint(n + 1);

    long long *rl = new long long[n + 1];
    long long *lr = new long long[n + 1];


    lr[n] = a[n];
    for( int i = n - 1; i >= 0; i-- )
    {
        lr[i] = lr[ i + 1 ] + a[i];
    }

    long long ans = 1;
    long long pre = 1;
    for( int i = 1; i <= n; i++ )
    {
        pre = min(lr[i], (pre - a[i - 1]) * 2 );
        if( pre <= 0 )
        {
            cout << -1;
            return 0;
        }
        ans += pre;
    }
    if( pre != a[n] ) ans = -1;
    cout << ans;
   return 0;    
}