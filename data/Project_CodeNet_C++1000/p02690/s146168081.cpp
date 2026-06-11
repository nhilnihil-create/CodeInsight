#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <set>

int main()
{
    int64_t X;
    std::cin >> X;

    int64_t x = 1;
    int64_t b = 0;
    while (true) {

        if (x * x * x * x * x - b > 1000000000) {
            break;
        }
        b = x * x * x * x * x;
        ++x;
    }

    for (int64_t i = -x; i < x; ++i)
    {
        for (int64_t j = -x; j < x; ++j)
        {
            if (i * i * i * i * i - j * j * j * j * j == X) {
                std::cout << i << " " << j << std::endl;
                return 0;
            }
        }
    }

    return 0;
}
