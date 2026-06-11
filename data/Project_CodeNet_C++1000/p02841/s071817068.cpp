#include <iostream>
#include <vector>

int main()
{
    int M1, D1, M2, D2;
    std::cin >> M1 >> D1 >> M2 >> D2;
    if (M1 != M2) {
        std::cout << 1 << std::endl;
    } else {
        std::cout << 0 << std::endl;
    }
    return 0;
}