#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    long s;
    scanf("%ld", &s);
    long x1 = 1000000000;
    long x2 = 1;
    long y2 = ceil(double(s) / x1);
    long y1 = y2 * x1 - s;
    printf("0 0 %ld %ld %ld %ld", x1, x2, y1, y2);
    return 0;
}
