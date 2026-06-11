#include <iostream>

int main(){
    int k, x;
    std::cin >> k >> x;

    if (x <= 500 * k)
    {
        std::cout << "Yes" << std::endl;
    }
    else
    {
        std::cout << "No" << std::endl;
    }

    return 0;
}