#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <array>
#include <climits>

const int MAXN = 200001;

long double solve(int& N, std::vector<int>& v)
{
    std::sort(v.begin(), v.end());
    long double sum = v[0];
    
    for (int i = 1; i < v.size(); i++)
    {
        sum += v[i];
        sum /= 2.0;
    }

    return sum;
}

int main()
{
    int N; std::cin >> N;
    std::vector<int> v(N, 0);
    for (int i = 0; i < N; i++)
    {
        std::cin >> v[i];
    }

    long double ans = solve(N, v);

    std::cout << ans << std::endl;
    return 0;
}