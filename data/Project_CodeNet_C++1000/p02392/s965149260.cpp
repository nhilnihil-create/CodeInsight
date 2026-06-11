#include <iostream>

int main()
{
    int a, b, c;
    std::cin >> a >> b >> c;
    (a < b && b < c) ? std::cout << "Yes" : std::cout << "No";
    std::cout << std::endl;
    return 0;
}