#include <cmath>
#include <iostream>
#include <vector> 
#include <algorithm>

int main()
{
    long long N;
    std::cin >> N;
    std::vector<long long> A(N, 0);
    for (int i=0; i<N; i++)
    {
        std::cin >> A.at(i);
    }

    int M = 1000005;
    std::vector<long long> cnt(M, 0);
    for (const long long& i: A)
    {
        if (cnt.at(i)!=0)
        {
            cnt.at(i)++;
            continue;
        }

        for (int j=i; j<M; j+=i) cnt.at(j)++;
    }

    long long ans=0;
    for (const long long& i: A)
    {
        if (cnt.at(i) == 1) ans++;
    }
    std::cout << ans;
}