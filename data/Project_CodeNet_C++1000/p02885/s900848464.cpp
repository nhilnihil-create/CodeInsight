#include <iostream>

int main(){
    int a, b;
    std::cin >> a >> b;
    int c = 0;

    c = a - b * 2;
    if (c > 0)
    {
        std::cout << c << std::endl;
    }
    else
    {
        std::cout << 0 << std::endl;
    }
    
    return 0;
}