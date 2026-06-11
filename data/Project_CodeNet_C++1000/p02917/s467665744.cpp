#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <array>
#include <climits>

long long int solve(std::vector<long long int>& B)
{
    std::reverse(B.begin(), B.end());
    long long int sum = 0;
    for(int i = 0; i < B.size()-1; i++)
    {
        long long int temp = std::min(B[i], B[i+1]);
        sum += temp;
    }
    
    return sum;
}

int main()
{
    int N; std::cin >> N;
    std::vector<long long int> B(N+1, 0);
    B[0] = INT_MAX; B[N] = INT_MAX;
    
    for(int i = 1; i < N; i++)
    {
        std::cin >> B[i];
    }
    
    long long int ans = solve(B);

    std::cout << ans << std::endl;
    return 0;
}