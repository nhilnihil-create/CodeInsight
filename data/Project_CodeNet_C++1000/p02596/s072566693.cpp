#include <iostream>

int main()
{
    long long K;
    std::cin >> K;
    int x = 0;
    int count;
    for (count = 0; count < K; count++)
    {
        x = (x * 10 + 7) % K;
        if (x == 0)
            break;
    }
    if (count == K)
        std::cout << -1 << std::endl;
    else
        std::cout << count + 1 << std::endl;
}
