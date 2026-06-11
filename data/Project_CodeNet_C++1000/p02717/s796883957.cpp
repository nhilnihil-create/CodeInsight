#include <iostream>
#include <utility>
int main()
{
    int X,Y,Z;
    std::cin >> X;
    std::cin >> Y;
    std::cin >> Z;
    std::swap(X,Y);
    std::swap(X,Z);
    std::cout << X << " " << Y << " " << Z;
}
