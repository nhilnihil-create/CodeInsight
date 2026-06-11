#include <iostream>
using i64 = long long;

int main() {
    std::string s;
    std::cin >> s;
    int ret = 0;
    for (const char c : s) ret += c - '0';
    std::cout << (ret % 9 ? "No" : "Yes") << std::endl;

    return 0;
}
