
#include <iostream>
#include <string>

int main()
{
    std::string N;
    std::cin >> N;
    int64_t s = 0;
    for (auto n : N)
    {
        s += n - '0';
    }
    std::cout << (s % 9 ? "No" : "Yes") << std::endl;

    return 0;
}

