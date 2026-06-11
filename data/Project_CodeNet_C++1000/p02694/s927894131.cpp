#include <iostream>
#include <cmath>
using ll = long long;

int main() {
    ll x; std::cin >> x;
    ll y=0, n=100;
    while(n<x) {
        n += n/100;
        ++y;
    }
    std::cout << y << std::endl;

    return 0;
}