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
   
  
    ll n;
    cin >> n;
    ll a, b;
    cin >> a >> b;
    if (n <= a) {
        cout << n << endl;

    }
    else if (n <= b) {
        cout << a << endl;
    }
    else {
        ll x = (n / (a + b)) * a;
        x += min((n % (a + b)) , (a ));
        cout << x<< endl;
    }


    return 0;

}