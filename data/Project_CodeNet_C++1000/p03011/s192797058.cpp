#include <iostream>

int main()
{
    int p, q, r;
    std::cin >> p >> q >> r;

    std::cout << std::min(std::min(p + q, q + r), r + p) << std::endl;

    return 0;
}