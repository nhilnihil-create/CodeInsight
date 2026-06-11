#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <array>
#include <climits>

long long int solve(std::vector<long long int> H)
{
    long long int temp = 0, ans = 0;
    for (long unsigned int i = 0; i < H.size() - 1; i++)
    {
        if(H[i]>=H[i+1])
        {
            temp++;
        }
        else
        {
            ans = std::max(ans, temp);
            temp = 0;
        }
    }

    ans = std::max(ans, temp);
    return ans;
}

int main()
{
    int N; std::cin >> N;
    std::vector<long long int> H(N, 0);
    
    for(int i = 0; i < N; i++)
    {
        std::cin >> H[i];
    }
    
    long long int ans = solve(H);

    std::cout << ans << std::endl;
    return 0;
}