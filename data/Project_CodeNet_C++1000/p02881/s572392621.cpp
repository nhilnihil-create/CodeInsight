/**
 *    Author  : Ador
 *    Created : 24.07.2020
**/
#include <iostream>
#include <cstdio>
#include <iomanip>
#include <algorithm>
#include <string>
#include <cstring>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <cctype>
typedef long long int ll ;
typedef unsigned long long int ull ;
using namespace std ;
int main(void)
{
    ios_base::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
        //freopen("input.txt", "r", stdin) ;
        //freopen("output.txt", "w", stdout) ;
    ll n , a , b , i , result = pow(2 , 60) , flag = 0 ; cin >> n ;
    for(i = 2 ; i * i <= n ; ++i)
    {
        if(!(n % i))
        {
            a = i ;
            b = n / i ;
            flag = 1 ;
            result = min(result , ((a - 1) + (b - 1))) ;
        }
    }
    if(flag) cout << result << "\n" ;
    else cout << n - 1 << "\n" ;
    return 0 ;
}
