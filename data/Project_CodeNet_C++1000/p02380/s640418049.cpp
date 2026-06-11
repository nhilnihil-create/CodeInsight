#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <vector>
#include <cctype>
#include <cstdio>
#include <iomanip>
#define PI 3.1415926535
 
using namespace std;
 
string in, t;
double a, b, c;
 
 
int main(){
    cin >> a >> b >> c;
    cout << fixed << setprecision(5) << a*b*sin(c / 360 * 2 * PI) / 2 << endl;
    cout << fixed << setprecision(5) << sqrt(a*a + b*b - 2 * a*b*cos(c / 360 * 2 * PI)) + a + b << endl;
    cout << fixed << setprecision(5) << b*sin(c / 360 * 2 * PI) << endl;
}