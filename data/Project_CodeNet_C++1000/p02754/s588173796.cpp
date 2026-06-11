#include <algorithm>
#include <iostream>

int main() {
    long long n, a, b;
    std::cin >> n >> a >> b;
    
    long long const s = a + b;
    
    std::cout << ((n/s) * a + std::min(n % s, a) ) << std::endl;
}