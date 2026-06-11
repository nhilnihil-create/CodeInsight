#include <iostream>

int main() {
    unsigned long long int n;
    std::cin >> n;

    if (n & 1)
    {
        std::cout << 0 << std::endl;
    }
    else
    {
        n /= 2;
        unsigned long long int count = 0;
        unsigned long long int k = 5;
        while (k <= n)
        {
            count += n / k;
            k *= 5;
        }
        std::cout << count << std::endl;
    }

    return 0;
}