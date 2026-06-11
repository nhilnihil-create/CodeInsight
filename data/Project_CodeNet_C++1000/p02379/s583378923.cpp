#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    double xa, xb, ya, yb;
    cin >> xa >> ya >> xb >> yb;

    double dd = (yb - ya) * (yb - ya) + (xb - xa) * (xb - xa);
    double d = sqrt(dd);

    printf("%.6f\n", d);

    return 0;
}