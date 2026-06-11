#include <iostream>
#include <climits>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include <vector>
#include <utility>
#include <string>
#include <bits/stdc++.h>
#include <fstream>
#include <chrono>
using namespace std;

typedef long long LL;

/*
        time complexty
auto start = chrono::steady_clock::now();
    ............

auto endd = chrono::steady_clock::now();
auto dif =   endd- start;
cout << chrono::duration<double, milli>(dif).count() <<"ms"<<endl;

*/


bool prime(LL n )
{
    if ( n < 4) return true;

    if ( (n%2 == 0) || (n%3 == 0) ) return false ;

    LL c= 5;

    while (c*c <= n  ){

        if ( (n%c==0) || (n%(c+2)==0)  ) return false ;
        c+=6;
    }
   return true;
}


LL gcd(LL one,LL two)
{
    while(two!=0)
    {
        LL t=two;
        two=one%two;
        one=t;
    }
    return one;
}

LL a , b , ans ;

int main(){

cin >>a >> b;
LL g = gcd(a , b);

for (LL i = 1 ;i*i <= g ; i++)

    if ((g%i == 0) && (g%i == 0)){
        ans+=prime(i);

        if ( (g/i) != i)  ans+= prime(g/i) ;

    }


cout <<ans<<endl;

return 0 ;
}
