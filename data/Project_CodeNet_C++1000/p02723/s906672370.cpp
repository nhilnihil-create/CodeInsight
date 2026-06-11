#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

#define ll long long

int main()
{
    std::string S;
    std::cin >> S;

    bool is_similar = true;

    if(S[2] != S[3])
        is_similar = false;
    
    if(S[4] != S[5])
        is_similar = false;

    
    if(is_similar)
        std::cout << "Yes" << std::endl;
    else
        std::cout << "No" << std::endl;
}