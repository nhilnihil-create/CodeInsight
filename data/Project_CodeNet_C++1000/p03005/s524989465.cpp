#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    int n, k;
    std::cin >> n >> k;

    if (k == 1) {
        std::cout << 0 << std::endl;
    } else {
        std::cout << n - k << std::endl;
    }
}
