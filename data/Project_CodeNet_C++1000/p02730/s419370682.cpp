#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>

#define ll long long

int main()
{
    std::string S;
    std::cin >> S;

    int size = S.size();
    bool is_kaibun = true;
    int a = (size + 3) / 2 - 1;
    for(int i=0; i < (size-1)/2; i++) {
        if(S[i] != S[a + i]) {
            is_kaibun = false;
        }
    }

    if(is_kaibun) {
        std::cout << "Yes" << std::endl;
    }
    else {
        std::cout << "No" << std::endl;
    }
}