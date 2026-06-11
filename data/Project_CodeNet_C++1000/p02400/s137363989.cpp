#include    <iostream>
#include    <cstdio>

using namespace std;

int main() {
    double r;
    // const double PI = 3.14159265;
    const double PI = 3.14159265358979323846;

    cin >> r;
    printf("%.6f %.6f\n", r*r*PI, 2*r*PI);

    return 0;
}
