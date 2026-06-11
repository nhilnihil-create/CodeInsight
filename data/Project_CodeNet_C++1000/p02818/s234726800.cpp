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

    ll a, b, k;
    
    cin >> a >> b >> k;

    if (a >= k) {
        a -= k;
        cout << a << " " << b << endl;
        return 0;
    }
    k -= a;
    a = 0;
    b -= k;
    if (b < 0)b = 0;
    cout << a << " " << b << endl;
   


    return 0;

}