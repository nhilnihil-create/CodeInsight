#include <iostream>

int main(){
    int a, b, c;
    std::cin >> a >> b >> c;

    if (a - b >= c)
    {
        std::cout << 0 << std::endl;
    }
    else
    {
        std::cout << c - a + b << std::endl;
    }

    return 0;
}