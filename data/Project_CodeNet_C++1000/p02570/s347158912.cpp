#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>

#define ll long long

int main()
{
    int D, T, S;
    std::cin >> D >> T >> S;

    int sum = T * S;
    if(sum >= D) {
        std::cout << "Yes" << std::endl;
    }
    else {
        std::cout << "No" << std::endl;
    }
}