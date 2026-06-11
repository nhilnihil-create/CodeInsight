#include <iostream>
#include <iomanip>

int main()
{
    int d;
    while (std::cin >> d) {
        double s = 0.0;
        for (int i = 1; i < 600 / d; ++i) {
            s += d * d * d * i * i;
        }
        std::cout << (int)s << std::endl;
    }
}