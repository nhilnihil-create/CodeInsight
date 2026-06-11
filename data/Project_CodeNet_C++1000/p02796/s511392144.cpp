#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

int main() {
    auto n = 0;
    std::cin >> n;

    auto robots = std::vector<std::pair<std::int64_t, std::int64_t>>();
    for (auto i_ = 0; i_ < n; ++i_) {
        auto x = std::int64_t(0);
        auto l = std::int64_t(0);
        std::cin >> x >> l;
        robots.emplace_back(x, l);
    }

    std::sort(robots.begin(), robots.end(), [](const auto& a, const auto& b) { return a.first < b.first; });

    auto range = robots.front().first + robots.front().second;
    auto counter = -1;
    for (const auto& r : robots) {
        const auto x = r.first;
        const auto l = r.second;
        if (range <= (x - l)) {
            range = x + l;
        } else {
            counter++;

            if (range > (x + l)) {
                range = x + l;
            }
        }
    }

    std::cout << n - counter << std::endl;

    return 0;
}