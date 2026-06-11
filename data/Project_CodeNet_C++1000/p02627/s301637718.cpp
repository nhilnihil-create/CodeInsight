#include <iostream>
#include <string>
#include <ctype.h>

int main() 
{
    char str;

    std::cin >> str;
    if (isupper(str)) {
        std::cout << "A" << std::endl;
    }
    else
    {
        std::cout << "a" << std::endl;
    }
}