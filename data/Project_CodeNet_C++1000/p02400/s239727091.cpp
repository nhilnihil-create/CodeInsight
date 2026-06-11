#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
//
// Created by karayuu on 2018-12-23.
//

int main() {
    double r;
    cin >> r;

    double s = r * r * M_PI;
    double l = 2 * r * M_PI;

    printf("%.6lf %.6lf\n", s, l);
}
