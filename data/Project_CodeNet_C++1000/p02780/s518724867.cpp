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
    
    int k, n;
    cin >> n >> k;

    vector<int>p(n);

    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    long long int a = 0, b = -1;;
    for (int i = 0; i < k; i++) {
        a += p[i];
    }
    b = a;
    int r = k - 1;
    for (int i = k; i < n; i++) {
        a += p[i];
        a -= p[i - k];
        if (b < a) {
            b = a;
            r = i;
        }
    }
    double ans = 0;
    cout << setprecision(20);
    for (int i = r; i > r - k; i--) {
        ans += (double)(1 + p[i]) / 2;
    }
    cout << ans << endl;

    return 0;

}