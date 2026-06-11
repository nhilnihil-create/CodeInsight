#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <array>
#include <climits>

const int MAXN = 200001;

long long int solve(long long int& N)
{
    long long int ans = 1, i = 1;
    while(N!=1)
    {
        N = floor(N / 2);
        ans += pow(2, i);
        i++;
    }

    return ans;
}

int main()
{
    long long int H; std::cin >> H;

    long long int ans = solve(H);

    std::cout << ans << std::endl;
    
    return 0;
}