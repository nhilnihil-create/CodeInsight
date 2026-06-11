#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

#define ll         long long
#define PI         acos(-1.0)
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)

int main(){
    double a, b, C;
    cin >> a >> b >> C;
    double S, L, h;
    S = a * b * sin(PI*C/180) * 0.5;
    L = a + b + sqrt(a*a + b*b - 2 * a * b * cos(PI*C/180));
    h = 2 * S / a;
    printf("%.04lf\n", S);
    printf("%.04lf\n", L);
    printf("%.04lf\n", h);
}