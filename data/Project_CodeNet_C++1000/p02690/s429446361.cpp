#include <iostream>

long long pow5(long long x)
{
    return x * x * x * x * x;
}

int main()
{
    long long X;
    std::cin >> X;
    for (long long A = 0; pow5(A) <= 1000000000; A++)
    {
        for (long long B_ = 0; pow5(B_) <= 1000000000; B_++)
        {
            if (pow5(A) + pow5(B_) == X)
            {
                std::cout << A << " " << -B_ << std::endl;
                return 0;
            }
        }
    }
    for (long long A = 0; A <= 178; A++)
    {
        for (long long B = 0; B < A; B++)
        {
            if (pow5(A) - pow5(B) == X)
            {
                std::cout << A << " " << B << std::endl;
                return 0;
            }
        }
    }
}