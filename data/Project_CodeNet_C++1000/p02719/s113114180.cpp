#include <iostream>

int main()
{
    // -(N_0-3K)-0------(N_0-2K)-------(N_0-K)-------N_0--
    //  (N_0%K-K)        N_0 % K
    long long N, K;
    std::cin >> N >> K;
    long long right = N % K;
    long long left = right - K;
    std::cout << std::min(right, -left) << std::endl;
}