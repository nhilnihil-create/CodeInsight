#include<iostream>
#include<vector>


int main() {
    long long n, k;
    std::cin >> n >> k;

    long long modp = n % k;
    long long modm = std::abs(modp - k);

    std::cout << std::min(modp, modm) << "\n";
}