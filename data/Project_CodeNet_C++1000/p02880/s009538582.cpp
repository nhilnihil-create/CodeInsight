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
    int n , d , flag = 0 , i ; cin >> n ;
    for(i = 1 ; i <= 9 ; ++i)
    {
        if(!(n % i)) d = n / i ;
        if(d < 10) {flag = 1 ; break ; }
    }
    if(flag) cout << "Yes\n" ;
    else cout << "No\n" ;
    return 0 ;
}
