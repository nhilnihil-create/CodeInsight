#include <iostream>

int main(){
    int a, b;
    std::cin >> a >> b;

    if (a <= 9 && b <= 9)
    {
        std::cout << a * b << std::endl;
    }
    else
    {
        std::cout << -1 << std::endl;
    }
    
    return 0;
}