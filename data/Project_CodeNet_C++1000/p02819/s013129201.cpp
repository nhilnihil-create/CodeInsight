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

bool prime(LL num)
{
    if ( num < 4 ) return true;

    if (num%2==0 || num %3==0)return false;

    LL c=5;
    while( c*c <= num)
    {
        if (num%c==0 || num%(c+2)==0 )return false ;
        c+=6;
    }
    return true ;
}


int t, n ;

int main(){

scanf("%d",&n);
while(1)
{

  if ( prime(n) ) { cout <<n<<endl ; break ;}
  n++;
}

return 0;
}


