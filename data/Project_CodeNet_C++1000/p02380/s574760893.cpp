#include <iostream>
#include <cmath>

int main()
{
    double a, b, c, C;


    std::cin >> a >> b >> C;

    double S, L, h;


    S = a * b / 2.0 * std::sin(C/ 180* 3.1415926535897932);
    c = sqrt((a*a)+(b*b) - 2 * a * b * std::cos(C/180*3.14159265358979));
    L = a + b + c;
    h = S * 2 / a;



    std::printf("%lf\n",S);
    std::printf("%lf\n",L);
    std::printf("%lf\n",h);

    return 0;

}