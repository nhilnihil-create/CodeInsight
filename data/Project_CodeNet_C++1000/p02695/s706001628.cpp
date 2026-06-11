#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

struct A {
    int64_t a, b, c, d;
};

int64_t f(int64_t TT[10], const std::vector<A>& AA)
{
    int64_t s = 0;
    for (auto& a : AA) {
        if (TT[a.b - 1] - TT[a.a - 1] == a.c)
        {
            s += a.d;
        }
    }
    return s;
}

int main()
{
    size_t N,M,Q;
    std::cin >> N >> M >> Q;

    std::vector<A> t;
    for (size_t q = 0; q < Q; ++q)
    {
        A a;

        std::cin >> a.a >> a.b >> a.c >> a.d;

        t.push_back(a);
    }

    int64_t TT[10] = {1, 1, 1, 1, 1, 1, 1,  1, 1, 1};
    int64_t max = 0;

    while (true) {
        max = std::max(max, f(TT, t));

        if (TT[0] == M) {
            break;
        }

        for (size_t i = 0; i < N; ++i)
        {
            if (TT[N - 1 - i] != M) {
                ++TT[N - 1 - i];
                for (size_t j = N - 1 - i + 1; j < N; ++j) {
                    TT[j] = TT[N - 1 - i];
                }
                break;
            }
        }
    }
    std::cout << max << std::endl;

    return 0;
}
