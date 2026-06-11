#include <iostream>
using i64 = long long;

int main() {
    int n;
    std::cin >> n;

    i64 s = 0;
    for (int i = 1; i <= n; i++) {
        if (i % 3 && i % 5) s += i;
    }

    std::cout << s << std::endl;

    return 0;
}
