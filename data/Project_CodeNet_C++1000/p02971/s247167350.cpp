#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <array>
#include <climits>

void solve(int& N, std::vector<int>& A, std::vector<int>& Acp)
{
    for(int i = 0; i < N; i++)
    {
        if(A[i] != Acp[0]) std::cout << Acp[0] << std::endl;
        else std::cout << Acp[1] << std::endl;
    }
}

int main()
{
    int N; std::cin >> N;
    std::vector<int> A(N, 0), Acp(N, 0);

    for(int i = 0; i < N; i++) std::cin >> A[i];

    std::copy(A.begin(), A.end(), Acp.begin());
    std::sort(Acp.begin(), Acp.end(), std::greater<int>());
    
    solve(N, A, Acp);

    return 0;
}