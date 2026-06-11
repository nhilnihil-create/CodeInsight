#include <iostream>

// nyu-syutu-ryoku no settei wo suru
#include <iomanip>

// pi wo tukau ze
#include <math.h>

int main()
{
    double r, s, l, pi;

    // M_PI no yuko-suji ha 16-keta
    pi = M_PI;

    std::cin >> r;

    s = r * r * pi;
    l = r * 2 * pi;

    std::cout << std::fixed << std::setprecision(5)
      << s << " " << l << std::endl;

    return 0;
}