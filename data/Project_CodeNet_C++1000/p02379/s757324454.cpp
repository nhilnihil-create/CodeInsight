#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <ctype.h>
#include <algorithm>
#include <cmath>
 
#define REP(i, n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(),(x).end()
#define square(x) (x) * (x)
 
const int INF = 1e9;
 
using namespace std;
 
int main() {
    long double x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    long double result = sqrt(square(x2 - x1) + square(y2 - y1));
    cout << setprecision(10);
    cout << result << endl;
 
    return 0;
}