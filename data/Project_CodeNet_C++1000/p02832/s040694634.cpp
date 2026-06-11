#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <array>
#include <climits>

int solve(std::vector<int>& a)
{
    int num = 0;
    for(int i = 0; i < a.size(); i++)
    {
        if(a[i]==num+1)
        {
            num++;
        }
    }

    return a.size() - num;
}

int main()
{
    int N; std::cin >> N;
    std::vector<int> a(N, 0);
    bool cond = false;
    for(int i = 0; i < N; i++)
    {
        std::cin >> a[i];
        if(a[i]==1) cond = true;
    }
    int ans = -1;
    if (cond)
        ans = solve(a);
    std::cout << ans << std::endl;
    return 0;
}