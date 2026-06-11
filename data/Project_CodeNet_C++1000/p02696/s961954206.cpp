#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

#define ll long long

int main()
{
    ll A, B, N;
    std::cin >> A >> B >> N;

    // xはB以下になると思われる(0になるから)
    ll max = 0;
    ll x = N-4;

    if(N >= B) {
        max = (A * (B-1)) / B;
        //std::cout << max << std::endl;
    }
    else {
        max = A * N / B - A * (N / B);
    }
    std::cout << max << std::endl;
}