#include <iostream>
#include <vector>

void vector_setter(const int order, const int &N, const int &M, const int &Q, std::vector<int> &Arr,
                   std::vector<int> &a, std::vector<int> &b, std::vector<int> &c, std::vector<int64_t> &d,
                   int64_t &d_max)
{
    if (order == N)
    {
        int64_t sum = 0;

        for (int i = 0; i < Q; ++i)
        {
            if (Arr[b[i] - 1] - Arr[a[i] - 1] == c[i])
                sum += d[i];
        }

        if (d_max < sum)
            d_max = sum;
    }
    else
    {
        for (int i = Arr[order - 1]; i <= M; ++i)
        {
            Arr[order] = i;
            vector_setter(order + 1, N, M, Q, Arr, a, b, c, d, d_max);
        }
    }
}

int main()
{
    int N, M, Q;
    std::cin >> N >> M >> Q;

    std::vector<int> a(Q);
    std::vector<int> b(Q);
    std::vector<int> c(Q);
    std::vector<int64_t> d(Q);
    for (int i = 0; i < Q; ++i)
    {
        std::cin >> a[i] >> b[i] >> c[i] >> d[i];
    }

    std::vector<int> Arr(N);

    int64_t d_max = 0;
    for (int i = 1; i <= M; ++i)
    {
        Arr[0] = i;
        vector_setter(1, N, M, Q, Arr, a, b, c, d, d_max);
    }

    std::cout << d_max;
}