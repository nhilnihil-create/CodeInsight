#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <limits>
#include <set>
#include <map>

int main()
{
    int n{};
    std::cin >> n;
    std::string s(n, 'a');
    std::vector<std::string> result = { s };

    for (int i = 1; i < n; i++) {
        const auto tmp = result;
        for (auto x : tmp) {
            const auto c = *std::max_element(x.begin(), x.end()) + 1;
            while (x[i] < c) {
                x[i]++;
                result.emplace_back(x);
            }
        }
    }
    std::sort(result.begin(), result.end());
    for (auto&& x : result) {
        std::cout << x << std::endl;
    }
    return 0;
}