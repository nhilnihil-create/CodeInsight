#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <array>
#include <climits>

const int MAXN = 200001;

long long int solve(long long int N, long long int K)
{
    if (N % K == 0) return 0;
    else
    {
        long long int ans = N % K;
        return (long long int)std::min(K-ans, ans);
    }

}

int main()
{
    long long int N, K;
    std::cin >> N >> K;
    long long int ans = solve(N, K);

    std::cout << ans << std::endl;
    return 0;
}