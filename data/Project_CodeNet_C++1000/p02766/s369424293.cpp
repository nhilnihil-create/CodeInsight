#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

#define ll long long

int main()
{
    ll N, K;
    std::cin >> N >> K;

    int count = 0;
    while(N != 0) {
        count++;
        N /= K;
    }
    
    std::cout << count << std::endl;
}