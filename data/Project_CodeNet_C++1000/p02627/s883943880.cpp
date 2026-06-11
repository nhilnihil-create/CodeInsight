#include<iostream>

int main()
{
    char c;
    std::cin >> c;

    if( isupper(c) )
    {
        std::cout << "A";
        return 0;
    }
    std::cout << "a";
    return 0;
}