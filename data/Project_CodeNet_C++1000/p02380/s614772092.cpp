#include <iostream>
#include <iomanip> //setprecision
#include <cstdio>
#include <cstdlib>
#include <cmath>
#define PI 3.141592653589793

double surface(double a, double b, double C);
double length(double a, double b, double C);
double height(double a, double b, double C);

int main(void) {
    double a; // ????????????
    double b; // ????????????
    double C; // ?§?????????§??????
    std::cin >> a >> b >> C;
    C = C / 180 * PI;
    double S = surface(a, b, C);
    double L = length(a, b, C);
    double h = height(a, b, C);
    std::cout << std::fixed << std::setprecision(12);
    std::cout << S << std::endl;
    std::cout << L << std::endl;
    std::cout << h << std::endl;
    return EXIT_SUCCESS;
}

double surface(double a, double b, double C) {
    return a * b * sin(C) / 2.0;    
};

double length(double a, double b, double C) {
    double s = sqrt(a * a + b * b - 2 * a * b * cos(C)); 
    return a + b + s;
};

double height(double a, double b, double C) {
    double S = surface(a, b, C);
    return 2.0 * S / a;
};