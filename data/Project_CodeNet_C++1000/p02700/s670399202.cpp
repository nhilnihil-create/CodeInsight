#include <bits/stdc++.h>
#include <iostream>
#include <ctime>
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
//    int ti = clock();
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    while( a > 0 && c > 0 )
    {
        c -= b;
        if( c <= 0 ) break;
        a -= d;
    }
    
    if( a <= 0 )
    {
        cout << "No";
    }
    else
    {
        cout << "Yes";
    }
    

    //printf("Execution Time: %.4lf sec\n", 1.0 * (clock() - ti) / CLOCKS_PER_SEC);
    return 0;    
}