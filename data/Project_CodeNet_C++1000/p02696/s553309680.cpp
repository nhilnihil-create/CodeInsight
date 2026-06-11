#include <iostream>

int main()
{
    std::int64_t a, b, n;
    std::cin >> a >> b >> n;
    if (n < b)
    {
        std::cout << static_cast<int>(a * (static_cast<double>(n) / b)) << std::endl;
    }
    else
    {
        std::cout << static_cast<int>(a * ((b-1.0) / b)) << std::endl;
    }
}
