#include <iostream>
#include <algorithm>
#include <string>

int main()
{
    std::string s;
    std::cin >> s;
    if(s[0] == 'R')
    {
        std::cout << "Sunny";
    }
    else if(s[0] == 'S')
    {
        std::cout << "Cloudy";
    }
    else if(s[0] == 'C')
    {
        std::cout << "Rainy";
    }
    return 0;
}