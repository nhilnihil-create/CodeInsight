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
        for(int i=0; i < K; i++) {
            std::cout << S[i];
        }
        std::cout << "..." << std::endl;
    }
}