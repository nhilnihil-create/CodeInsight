#include <iostream>
#include <string>

int main()
{
    int S,W;
    std::cin >> S;
    std::cin >> W;
    if(W >= S) std::cout << "unsafe";
    else std::cout << "safe";
}
