#define _USE_MATH_DEFINES
#include  <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include<math.h>
#include<iomanip>
#include<stdio.h>
#include <stdlib.h>
#include<stdio.h>
#include <queue>
#include<map>
#include <sstream>
#include<set>
#include<stack>
#include<time.h>
typedef long long int ll;
//#include<bits/stdc++.h>


using namespace std;
 


int main()
{
   
    ll n, k;
    cin >> n >> k;

    string p;
    ll t = 0;
    while (n) {
        char a= n % k;
        a += '0';
        p = a + p;
        n /= k;
        t++;
    }
    cout << t << endl;

    return 0;

}