#include <iostream>

int main(){
    int a, b;
    std::cin >> a >> b;

    if ((a + b) % 2 == 0)
    {
        std::cout << (a + b) / 2 << std::endl;
    }
    else
    {
        std::cout << "IMPOSSIBLE" << std::endl;
    }
    
    return 0;
}