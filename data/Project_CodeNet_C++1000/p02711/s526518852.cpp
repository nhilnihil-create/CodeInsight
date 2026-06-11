#include <iostream>

int main(){
    int n;
    std::cin >> n;

    if (n % 10 == 7)
    {
        std::cout << "Yes" << std::endl;
        return 0;
    }
    n = n / 10;
    if (n % 10 == 7)
    {
        std::cout << "Yes" << std::endl;
        return 0;
    }
    n = n / 10;
    if (n == 7)
    {
        std::cout << "Yes" << std::endl;
        return 0;
    }

    std::cout << "No" << std::endl;
    return 0;
}