#include <iostream>

int main()
{
    int a, b, c;
    std::cin >> a >> b >> c;
    int d = c - (a - b);
    std::cout << ((d>0)?d:0) << std::endl;
    return 0;
}