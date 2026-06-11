#include<iostream>
#include<string>

bool check_upper(char c);

int main()
{
    char c;
    std::cin >> c;

    if( check_upper(c) )
    {
        std::cout << "A";
        return 0;
    }
    std::cout << "a";
    return 0;
}

bool check_upper(char c)
{
    if('A'<= c && c <='Z')
    {
        return true;
    }
    return false;
}