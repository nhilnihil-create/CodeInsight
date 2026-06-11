#include <algorithm>
#include <iostream>
#include <cstdio>

int main()
{
    int a = 0, b = 0;
    std::cin >> a >> b;
    std::cout << a / b << " " << a % b << " ";
    printf("%.5f", (double)a / b);
    return 0;
}
