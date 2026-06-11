#include <iostream>

auto main () -> int
{
    int a , b;
    std::cin >> a >> b;
//    std::cout << (a / b) << ' ' << (a % b) << ' ' << (static_cast <double> (a) / b) << std::endl;
    std::cout << (a / b) << ' ' << (a % b) << ' ';
    std::printf ("%.5f\n" , (double)a/b);
}