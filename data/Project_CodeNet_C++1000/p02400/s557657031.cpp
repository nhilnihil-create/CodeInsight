#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double r;
    cin >> r;
    constexpr double PI = acos(-1);
    printf("%f %f\n", PI*r*r, 2*PI*r);

    return 0;
}
