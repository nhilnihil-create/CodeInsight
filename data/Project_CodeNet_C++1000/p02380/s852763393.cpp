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
    long double a, b, C;
    long double S, L, h;
    cin >> a >> b >> C;
    long double rad = 2 * M_PI * C / 360;
    S = a * b * sin(rad) / 2;
    L = a + b + sqrt(square(a) + square(b) - 2 * a * b * cos(rad));
    h = b * sin(rad);
    cout << setprecision(10);
    cout << S << " " << L << " " << h << endl;
 
    return 0;
}