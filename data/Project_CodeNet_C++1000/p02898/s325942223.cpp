#include <iostream>
#include <vector>

int main() {
    int n, k; std::cin >> n >> k;
    int c = 0;
    std::vector<std::pair<int, int>> a;
    for (int i = 0; i < n; i++) {
        int h; std::cin >> h;
        if (h >= k) {
            c++;
        }
    }
    std::cout << c << std::endl;
    return 0;
}