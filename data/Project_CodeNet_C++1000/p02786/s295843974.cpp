#include <bits/stdc++.h>
using namespace std ;
int main()
{
    long long n , num = 2 ;
    long long cnt = 1 ;
    cin >> n ;
    long long x = 1;

        while(n > 1)
        {
            cnt += num ;
            n = n / 2 ;
            x = num * n ;
            num *= 2 ;
        }
    cout << cnt <<"\n" ;
}

