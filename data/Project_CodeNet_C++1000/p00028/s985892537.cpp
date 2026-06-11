#include <iostream>
#include <array>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, max_cnt = -1;
    std::array<int, 101> arr{{}};
    
    while (std::cin >> n) {
        max_cnt = (max_cnt > ++arr[n]
                   ? max_cnt : arr[n]);
    }

    for (int i = 1; i < 101; ++i) {
        if (arr[i] == max_cnt) {
            std::cout << i << std::endl;
        }
    }

    return 0;
}