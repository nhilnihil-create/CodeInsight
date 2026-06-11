#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <array>
#include <climits>

const int MAXN = 200001;

int main()
{
    int K, N;
    std::cin >> K >> N;
    std::vector<int> A(N, 0);
    
    for (int i = 0; i < N; i++)
    {
        std::cin >> A[i];
    }
    
    int ans = K - A[N-1] + A[0];
    for (int i = 1; i < N; i++)
    {
        ans = std::max(ans, A[i] - A[i-1]);
    }

    std::cout << K - ans << std::endl;
    return 0;
}