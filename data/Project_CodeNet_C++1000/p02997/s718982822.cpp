#include <iostream>

int n, k;

int main()
{

    std::cin >> n >> k;

    int max = (n - 1) * (n - 2) / 2;

    if (k > max)
        std::cout << -1 << std::endl;

    else
    {

        int m = n - 1 + max - k;

        std::cout << m << std::endl;

        for (int i = 0; i < n - 1; ++i)
            std::cout << 1 << ' ' << i + 2 << std::endl;

        int node = 2;

        for (int i = 0; i < max - k; ++i)
        {

            int j = n * (node - 2) - (node - 2) * (node + 1) / 2;

            std::cout << node << ' ' << i - j + node + 1 << std::endl;

            if (i == j + n - node - 1)
                ++node;
        }
    }

    return 0;
}