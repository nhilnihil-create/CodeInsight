#include <iostream>
#include <array>
#include <functional>
#include <utility>
#include <regex>

int main()
{
    int64_t N, M, X;
    std::cin >> N >> M >> X;
    std::vector<int64_t> C;
    std::vector<std::vector<int64_t>> A(N);

    for (int64_t n = 0; n < N; ++n)
    {
        int64_t c;
        std::cin >> c;
        C.emplace_back(c);
        std::vector<int64_t> v;
        for (int64_t m = 0; m < M; ++m)
        {
            int64_t a;
            std::cin >> a;
            v.emplace_back(a);
        }
        A[n] = std::move(v);
    }
    int64_t v = std::numeric_limits<int64_t>::max();
    for (int64_t i = 1; i <= (1 << N) - 1; ++i)
    {
        std::vector<int64_t> S(A[0].size());
        int64_t c = 0;
        for (int64_t j = 0; j < N; ++j)
        {
            if ((i >> j) & 1) {
                for (int64_t t = 0; t < M; ++t)
                {
                    S[t] += A[j][t];
                }
                c += C[j];
            }
        }
        bool ng = false;
        for (int64_t t = 0; t < M; ++t)
        {
            if (S[t] < X) {
                ng = true;
                break;
            }
        }
        if (!ng) {
            v = std::min(v, c);
        }
    }

    std::cout << (v == std::numeric_limits<int64_t>::max() ? -1 : v) << std::endl;

    return 0;
}

