#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

int main()
{

    double s, l, h, sdA, sdB, sdC, agC;
    scanf("%lf %lf %lf", &sdA, &sdB, &agC);
    agC = agC * M_PI / 180;
    s = sdA * sdB * sin(agC) / 2;
    printf("%lf\n", s);
    sdC = sqrt(sdA * sdA + sdB * sdB - 2 * sdA * sdB * cos(agC));
    l = sdA + sdB + sdC;
    printf("%lf\n", l);
    h = s * 2 / sdA;
    printf("%lf\n", h);
}
