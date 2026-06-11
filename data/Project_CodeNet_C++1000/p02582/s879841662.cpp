#include <iostream>
#include <string>
using i64 = long long;

int main() {
    std::string s;
    std::cin >> s;

    const int ret = s == "RRR"
        ? 3
        : s == "RRS" || s == "SRR"
            ? 2
            : s != "SSS" ? 1 : 0;

    std::cout << ret << std::endl;

    return 0;
}
