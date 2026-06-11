#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    auto n = std::size_t();

    std::cin >> n;

    auto x = std::vector<int>(n);
    auto l = std::vector<int>(n);

    for (std::size_t i = 0; i < n; ++i) std::cin >> x[i] >> l[i];

    auto section = std::vector<std::pair<int, int>>();
    for (std::size_t i = 0; i < n; ++i) section.emplace_back(x[i] + l[i], x[i] - l[i]);

    auto comp = [](auto a, auto b) { return a.first < b.first; };
    std::sort(section.begin(), section.end(), comp);

    auto result = std::size_t(n);
    auto t = section[0].first;
    for (std::size_t i = 1; i < n; ++i)
    {
        if (section[i].second < t)
            --result;
        else
            t = section[i].first;
    }

    std::cout << result << std::endl;

    return 0;
}