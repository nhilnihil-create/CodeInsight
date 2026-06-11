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

const int S = 1e7+3;
LL ans=0 ,  n ;

int a[S];

int main(){

scanf("%lld",&n);

for(LL i = 2 ; i <= n; i++){

    for(int j = i ; j <= n ; j+=i)
     a[j]+= 1;

  ans+=(max( a[i] , 1 )+1)*i;
}

cout <<ans+1;

return 0;
}
