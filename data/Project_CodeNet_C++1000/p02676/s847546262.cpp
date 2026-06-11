#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

#define ll long long

int main()
{
    int K;
    std::cin >> K;

    std::string S;
    std::cin >> S;

    int S_size = S.size();

    if(S_size <= K) {
        std::cout << S << std::endl;
    }
    else {
        std::cout << S.substr(0,K) << "..." << std::endl;
    }
}