#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <regex>
#include <set>
#include <cmath>
#include <sstream>
#include <numeric>
#include <set>

int main()
{
    long long n, k;
    std::cin >> n;
    std::cin >> k;
    std::vector<long long> heights;

    for(long long i = 0; i < n; i++)
    {
        long long h;
        std::cin >> h;
        heights.push_back(h);
    }

    long long ans = std::count_if(heights.begin(), heights.end(), [&k](auto x){ return x >= k; });

    std::cout << ans;

    return EXIT_SUCCESS;
}
