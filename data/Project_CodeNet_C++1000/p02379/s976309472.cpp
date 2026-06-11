#include <math.h>
#include <stdio.h>

#include <cmath>
#include <iostream>
#include <string>
using namespace std;

int main() {
    const float t = 100000000;
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    double res;

    res = (sqrt(pow(((x2 - x1)), 2) + pow(((y2 - y1)), 2)));

    printf("%.5f\n", res);
    return 0;
}
