#include <iostream>

int main() {
    long double A, B;

    std::cin >> A >> B;

    B = (long long int)(B * 100 + 0.001);
    long long int ans = (long long int)(A * B / 100);

    std::cout << ans << std::endl;

    return 0; 
}
