#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

#define ll long long

int main()
{
    int N;
    std::cin >> N;

    bool is_contain = false;
    while(true) {
        if(N == 0) {
            break;
        }
        int tmp = N % 10;
        if(tmp == 7) {
            is_contain = true;
            break;
        }
        N = N / 10;
    }

    if(is_contain) {
        std::cout << "Yes" << std::endl;
    }
    else {
        std::cout << "No" << std::endl;
    }
}