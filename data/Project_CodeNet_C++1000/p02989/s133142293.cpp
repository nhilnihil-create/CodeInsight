#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <array>
#include <climits>

const int MAXN = 200001;

long long int solve(int& N, std::vector<int>& d)
{
    std::sort(d.begin(), d.end());

    return d[N/2] - d[N/2-1];
}

int main()
{
    int N; std::cin >> N;
    std::vector<int> d(N, 0);
    for (int i = 0; i < N; i++)
    {
        std::cin >> d[i];
    }

    long long int ans = solve(N, d);

    std::cout << ans << std::endl;
    return 0;
}