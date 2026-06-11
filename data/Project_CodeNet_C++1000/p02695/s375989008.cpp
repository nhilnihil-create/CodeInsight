#include <iostream>
#include <tuple>
#include <vector>
#include <array>

int calc(int pos, int N, int X, int M, std::array<int, 10> &A, std::vector<std::tuple<int, int, int, int>> const &constraints)
{
    if (pos == N)
    {
        int score = 0;
        for (auto const &constraint : constraints)
        {
            int a = std::get<0>(constraint) - 1;
            int b = std::get<1>(constraint) - 1;
            int c = std::get<2>(constraint);
            if (A[b] - A[a] == c)
            {
                score += std::get<3>(constraint);
            }
        }
        return score;
    }
    int max = 0;
    for (int i = X; i <= M; i++)
    {
        A[pos] = i;
        max = std::max(max, calc(pos + 1, N, i, M, A, constraints));
    }
    return max;
}

int main()
{
    int N, M, Q;
    std::cin >> N >> M >> Q;
    std::vector<std::tuple<int, int, int, int>> constraints(Q);
    for (int i = 0; i < Q; i++)
    {
        std::cin >> std::get<0>(constraints[i]);
        std::cin >> std::get<1>(constraints[i]);
        std::cin >> std::get<2>(constraints[i]);
        std::cin >> std::get<3>(constraints[i]);
    }

    std::array<int, 10> A;
    std::cout << calc(0, N, 1, M, A, constraints) << std::endl;
}