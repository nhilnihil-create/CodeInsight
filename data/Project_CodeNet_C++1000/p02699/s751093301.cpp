#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

#define ll long long

int main()
{
    int S, W;
    std::cin >> S >> W;

    if(W >= S) {
        std::cout << "unsafe" << std::endl;
    }
    else {
        std::cout << "safe" << std::endl;
    }
}