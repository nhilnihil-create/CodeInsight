#include <cmath>
#include <iostream>

void koch(int n, double p1x, double p1y, double p2x, double p2y)
{
    if (n == 0) return;

    double sx = 2.0 * p1x / 3.0 + p2x / 3.0;
    double sy = 2.0 * p1y / 3.0 + p2y / 3.0;

    double tx = p1x / 3.0 + 2.0 * p2x / 3.0;
    double ty = p1y / 3.0 + 2.0 * p2y / 3.0;

    double ux = (tx + sx) / 2.0 + sqrt(3.0) * (sy - ty) / 2.0;
    double uy = sqrt(3.0) * (tx - sx) / 2.0 + (ty + sy) / 2.0;

    koch(n-1, p1x, p1y, sx, sy);
    std::cout << sx << " " << sy << std::endl;
    koch(n-1, sx, sy, ux, uy);
    std::cout << ux << " " << uy << std::endl;
    koch(n-1, ux, uy, tx, ty);
    std::cout << tx << " " << ty << std::endl;
    koch(n-1, tx, ty, p2x, p2y);
}

int main(int argc, char const *argv[])
{
    int n;
    std::cin >> n;

    double p1x = 0.0;
    double p1y = 0.0;
    double p2x = 100.0;
    double p2y = 0.0;

    std::cout << p1x << " " << p1y << std::endl;
    koch(n, p1x, p1y, p2x, p2y);
    std::cout << p2x << " " << p2y << std::endl;

    return 0;
}