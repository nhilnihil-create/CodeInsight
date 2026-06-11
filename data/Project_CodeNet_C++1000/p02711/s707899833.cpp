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
    int t;
    cin >> t;

    while (t) {
        if (t % 10 == 7) {
            cout << "Yes" << endl;
            return 0;
        }
        t /= 10;
    }

    cout << "No" << endl;

    return 0;

}