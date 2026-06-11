#include <iostream>
#include <vector>
#include <memory>

int main()
{
    int N;
    long long K;
    std::cin >> N >> K;
    std::vector<int> dir(N + 1);
    for (int i = 1; i <= N; i++)
    {
        int A;
        std::cin >> A;
        dir[i] = A;
    }
    std::vector<long long> visited(N + 1);
    for (auto &&e : visited)
        e = -1;
    int pos = 1;
    visited[1] = 0;
    for (long long i = 1; i <= K; i++)
    {
        pos = dir[pos];
        if (visited[pos] == -1)
        {
            visited[pos] = i;
        }
        else
        {
            long long diff = i - visited[pos];
            i += (K - i) / diff * diff;
        }
    }
    std::cout << pos << std::endl;
}