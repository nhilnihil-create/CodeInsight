#include <iostream>
#include <string>

const unsigned int MOD = 1000000007;

int main() {
    std::string L;
    std::cin >> L;

    unsigned int x = 1, y = 0;
    for (char c : L) {
        y = y * 3 % MOD;
        if (c == '1') {
            y = (y + x) % MOD;
            x = x * 2 % MOD;
        }
    }

    std::cout << (x + y) % MOD << "\n";
}