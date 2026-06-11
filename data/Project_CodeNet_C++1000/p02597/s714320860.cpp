#include <iostream>
#include <vector>

int main()
{
    int N;
    std::cin >> N;
    std::vector<char> c(N);
    int n_red = 0;
    for (auto &&e : c)
    {
        std::cin >> e;
        if (e == 'R')
            n_red++;
    }
    int r_diff = 0;
    for (int i = 0; i < n_red; i++)
    {
        if (c[i] == 'W')
            r_diff++;
    }
    int w_diff = 0;
    for (int i = n_red; i < N; i++)
    {
        if (c[i] == 'R')
            w_diff++;
    }
    std::cout << std::max(r_diff, w_diff) << std::endl;
}