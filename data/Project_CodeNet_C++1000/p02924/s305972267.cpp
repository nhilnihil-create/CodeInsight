#include <iostream>
#include <vector>

int main()
{
    long long N;
    std::cin >> N;
    N--;
    std::cout << N * (N + 1) / 2 << std::endl;
    return 0;
}