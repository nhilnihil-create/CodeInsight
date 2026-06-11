#include <iostream>

int main()
{
    int64_t A, B, N;
    std::cin >> A >> B >> N;

    int64_t starter = N / B;
    starter *= B;
    if (starter == 0)
        starter = B;
    int64_t max_num = 0;
    for (int64_t x = starter; x <= N; x += B)
    {
        int64_t calcx = x - 1;
        int64_t first = A * calcx / B;
        int64_t second = calcx / B;

        int64_t result = first - A * second;
        if (max_num < result)
            max_num = result;
    }
    int64_t calcx = N;
    int64_t first = A * calcx / B;
    int64_t second = calcx / B;

    int64_t result = first - A * second;
    if (max_num < result)
        max_num = result;

    std::cout << max_num;
}