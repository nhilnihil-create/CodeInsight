#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> x(5);

    for(int i = 0; i < 5; i++) {
        std::cin >> x.at(i);
    }

    auto iter = std::find(x.begin(), x.end(), 0);
    auto dist = std::distance(x.begin(), iter);

    std::cout << dist + 1 << std::endl;

    return 0;
}
