#include <algorithm>
#include <iostream>
#include <cstdio>

int main()
{
    int a = 0, b = 0;
    for (std::cin >> a >> b; a || b ; std::cin >> a >> b)
        if (a > b)
            std::cout << b << " " << a << std::endl;
        else
            std::cout << a << " " << b << std::endl;
    return 0;
}
