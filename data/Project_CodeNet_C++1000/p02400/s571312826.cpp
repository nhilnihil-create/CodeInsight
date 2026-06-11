#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define REP(i,n) for(int (i)=0; (i)<(n); (i)++)
#define For(i,a,b) for(int (i)=(a); (i)<(b); (i)++)

int main() {
    double r;
    cin >> r;
    const double pi = acos(-1);
    double area = pi * r * r;
    double peri = 2 * r * pi;
    printf("%6f %6f\n", area, peri);
    return 0;
}