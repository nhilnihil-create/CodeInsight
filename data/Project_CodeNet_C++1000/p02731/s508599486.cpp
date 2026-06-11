#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>

#define ll long long

int main()
{
    double L;
    std::cin >> L;

    //std::cout << L * L * L / 27.0 << std::endl;
    printf("%.7f\n", L*L*L/27);

    return 0;
}