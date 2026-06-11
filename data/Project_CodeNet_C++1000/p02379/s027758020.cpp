#include <iostream>
#include <math.h>
#include <cstdio>
using namespace std;

int main(void){
    long double x1, x2, y1, y2;

    cin >> x1 >> y1 >> x2 >> y2;
    printf("%.8lf\n", pow((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1), 0.5));
}