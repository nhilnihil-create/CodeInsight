#include <iostream>
#include <cstdio>
#define M_PI 3.14159265359
using namespace std;
 
int main() {
    double r;
    cin >> r;

    double area = r * r * M_PI;
    double circum = 2 * r * M_PI;

    printf("%.6f %.6f\n", area, circum);
}