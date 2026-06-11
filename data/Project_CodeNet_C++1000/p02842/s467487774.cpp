#include <iostream>
constexpr int n_max = 50'000;  //'

int main(void) {
    int n;
    std::cin >> n;

    for (int x = 1; x < n_max; ++x) {
        int t = x * 1.0800;
        if (t == n) {
            std::cout << x << std::endl;
            return 0;
        }
        if (t > n) break;
    }

    std::cout << ":(\n";
    return 0;
}
