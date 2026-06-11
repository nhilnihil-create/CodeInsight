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
   
   
    string p;
    cin >> p;
    int r = 0;
    int a = 0;

    for (int i = 0; i < 3; i++) {
        if (p[i] == 'R')a++;
        else a = 0;
        r = max(r, a);
    }

    cout << r << endl;

    return 0;

}