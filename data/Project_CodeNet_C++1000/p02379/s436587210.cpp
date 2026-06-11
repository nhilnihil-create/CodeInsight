#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define REP(i,n) for(int (i)=0; (i)<(n); (i)++)
#define For(i,a,b) for(int (i)=(a); (i)<(b); (i)++)

int main() {
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    double r = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
    printf("%6f\n" , r);
    return 0;
}