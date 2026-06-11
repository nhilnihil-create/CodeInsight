#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main()
{
    double x1, x2, y1, y2, dx, dy, distance;
    cin >> x1 >> y1 >> x2 >> y2;
    dx = x2 - x1;
    dy = y2 - y1;
    distance = sqrt(dx * dx + dy * dy);
    printf("%10.8f\n", distance);
}
