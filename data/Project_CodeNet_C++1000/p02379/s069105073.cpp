#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

double func_distance(double x1, double y1, double x2, double y2) {
    double x_length = x2 - x1;
    double y_length = y2 - y1;
    double distance = sqrt(pow(x_length, 2) + pow(y_length, 2));
    return distance;
}

int main() {
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    
    printf("%f\n", func_distance(x1, y1, x2, y2));
}