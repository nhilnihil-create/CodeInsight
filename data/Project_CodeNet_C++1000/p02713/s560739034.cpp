#include <iostream>
#include <algorithm>

int main()
{
    int K;
    std::cin >> K;
    int sum = 0;
    for (int a = 1; a <= K; a++)
    {
        for (int b = 1; b <= K; b++)
        {
            int gcd_ab = std::__gcd(a, b);
            for (int c = 1; c <= K; c++)
            {
                sum += std::__gcd(gcd_ab, c);
            }
        }
    }
    std::cout << sum << std::endl;
}