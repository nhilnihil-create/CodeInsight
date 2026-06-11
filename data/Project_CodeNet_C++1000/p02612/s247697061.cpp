#include <iostream>
#include <string>

static const int MONEY = 1000; 

int main() 
{
    unsigned int goods = 0;
    unsigned int num = 0;

    std::cin >> goods;
    if (1 > goods || 10000 < goods)
    {
        std::cout << "No goods" << std::endl;
        return -1;
    }
    num = goods % MONEY;

    if (0 == num) {
        std::cout << "0" << std::endl;
    }
    else
    {
        num = MONEY - num;
        std::cout <<  num;
    }
    return 0;
}