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

//#include<bits/stdc++.h>


using namespace std;


int main()
{
    
    string p;
    cin >> p;

    long long int ans = 0;
    int t = 0;
    long long int c[2023] = {};
    c[t] = 1;
    int n = p.size();
    
    reverse(p.begin(), p.end());
    int d = 1;
    for (int i = 0; i < n; i++) {
        t = t + (p[i] - '0') * d;
        t %= 2019;
        ans+=c[t];

        c[t]++;
        d *= 10;
        d %= 2019;
    }
    cout << ans << endl;

    return 0;

}