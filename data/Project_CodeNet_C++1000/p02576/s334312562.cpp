

#include <iostream>

int main()
{
    int64_t N, X, T;
    std::cin >> N >> X >> T;

    std::cout << ((N / X) + ((N % X) ? 1: 0)) * T << std::endl;

    return 0;
}

