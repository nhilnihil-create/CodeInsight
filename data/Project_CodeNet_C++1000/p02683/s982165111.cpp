#include <iostream>
#include <vector>
#include <cmath>

int main()
{
    int N, M, X;
    std::cin >> N >> M >> X;
    std::vector<std::vector<int>> CA;
    CA.resize(N);
    for (int i = 0; i < N; i++)
    {
        int C;
        std::cin >> C;
        CA[i].push_back(C);
        for (int j = 0; j < M; j++)
        {
            int A;
            std::cin >> A;
            CA[i].push_back(A);
        }
    }
    uint32_t min = UINT32_MAX;
    for (uint16_t pat = 0; pat < 1 << N; pat++)
    {
        std::vector<int> wakari(M);
        for (uint8_t i = 0; i < N; i++)
        {
            if (pat >> i & 1)
            {
                for (int j = 0; j < M; j++)
                {
                    wakari[j] += CA[i][j + 1];
                }
            }
        }

        // check
        bool ok = true;
        for (auto const &e : wakari)
        {
            if (e < X)
                ok = false;
        }
        if (ok)
        {
            uint32_t cost = 0;
            for (uint8_t i = 0; i < N; i++)
            {
                if (pat >> i & 1)
                {
                    cost += CA[i][0];
                }
            }
            min = std::min(min, cost);
        }
    }
    if (min == UINT32_MAX)
        std::cout << -1 << std::endl;
    else
        std::cout << min << std::endl;
}
