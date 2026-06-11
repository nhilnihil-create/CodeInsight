#include <cstdio>
#include <vector>
#include <algorithm>

int main()
{
    int N;

    scanf("%d", &N);

    std::vector<int64_t> C(N, 0);
    std::vector<int64_t> D(N + 1, 0);
    for (int i = 0; i < N; ++i)
    {
        int a;
        scanf("%d", &a);
        C[--a]++;
        D[C[a]]++;
    }

    std::vector<int64_t> S(N + 1, 0);
    for (int i = 1; i <= N; ++i)
    {
        S[i] = S[i - 1] + D[i];
    }

    for (int K = 1; K <= N; ++K)
    {
        int64_t low = 0, high = N + 1;
        while (high - low > 1)
        {
            int64_t x = (low + high) / 2;
            if (S[x] >= K * x)
            {
                low = x;
            }
            else
            {
                high = x;
            }
        }
        printf("%lld\n", low);
    }
}
