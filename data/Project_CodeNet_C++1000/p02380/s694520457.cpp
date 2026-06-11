#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.14159265359
using namespace std;

double func_area(double base, double height) {
    double area = base * height / 2.0;
    return area;
}

double func_circumference(double a, double b, double c_x, double c_y) {
    double left_base = fabs(b - c_x);
    double third_line = sqrt(pow(left_base, 2.0) + pow(c_y, 2.0));
    double sum = a + b + third_line;
    return sum;
}

int main() {
    double a, b, c;
    double c_x, c_y, c_y2;
    cin >> a >> b >> c;
    double rad = c * PI / 180;
    
    double radius_a = a;
    double radius_b = b;
    

    c_x = cos(rad) * radius_a;
    c_y = sin(rad) * radius_a;
    c_y2 = sin(rad) * radius_b;
    
    printf("%f\n%f\n%f\n", func_area(b, c_y), func_circumference(a, b, c_x, c_y), c_y2);
}