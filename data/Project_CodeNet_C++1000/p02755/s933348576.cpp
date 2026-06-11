#include <cmath>
#include <iostream>

int main() {
    int a, b;
    std::cin >> a >> b;
    
    for(int i = 1; i <= 1250; ++i)
    {
        if(static_cast<int>(std::floor(i * 0.08)) == a
           && static_cast<int>(std::floor(i * 0.1)) == b)
        {
            std::cout << i << std::endl;
            return 0;
        }
    }
    
    std::cout << "-1" << std::endl;
}