#include <iostream>
#include <vector>

int main()
{
    long long K;
    std::cin >> K;
    // [1, 2, 3, 4, 5, 6, 7, 8, 9] 9個
    // [10, 11, 12, 21, 22, 23, 32, 33, 34, ..., 89, 98, 99] 9*3-1 = 26個
    // [100, 101, 110, 111, 112, ..., 998, 999] 26*3-3 = 75個
    // [1000, 1001, ...]
    std::vector<long long> lunlun_seq;
    lunlun_seq.reserve(K);
    for (long long i = 1; i < 10; i++)
    {
        lunlun_seq.push_back(i);
    }
    long long index = 0;
    while (lunlun_seq.size() < K)
    {
        long long prior = lunlun_seq[index];
        long long first = prior - (prior / 10) * 10;
        if (first != 0)
            lunlun_seq.push_back(10 * prior + first - 1);
        lunlun_seq.push_back(10 * prior + first);
        if (first != 9)
            lunlun_seq.push_back(10 * prior + first + 1);
        index++;
    }
    std::cout << lunlun_seq[K - 1] << std::endl;
}