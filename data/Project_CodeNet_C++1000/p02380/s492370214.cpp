#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define REP(i,n) for(int (i)=0; (i)<(n); (i)++)
#define For(i,a,b) for(int (i)=(a); (i)<(b); (i)++)

int main() {
    int a, b, C;
    cin >> a >> b >> C;
    double S, L, h;
    S = 0.5 * a * b * sin(C * acos(-1) / 180);
    h = S * 2 / a;
    L = a + b + sqrt(a*a + b*b - 2*a*b*cos(C * acos(-1) / 180));
    printf("%6f\n%6f\n%6f\n", S, L, h);
    return 0;
}