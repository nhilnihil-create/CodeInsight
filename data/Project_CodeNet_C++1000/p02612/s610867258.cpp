#include <iostream>
#include <string>
#include <ctype.h>

int main() 
{
    unsigned int goods = 0;
    unsigned int num = 0;

    std::cin >> goods;
    if (1 > goods || 10000 < goods)
    {
        std::cout << "Error" << std::endl;
        return -1;
    }
    num = goods % 1000;

    if (0 == num) {
        std::cout << "0" << std::endl;
    }
    else
    {
        num = 1000 - num;
        std::cout <<  num;
    }
    return 0;
}