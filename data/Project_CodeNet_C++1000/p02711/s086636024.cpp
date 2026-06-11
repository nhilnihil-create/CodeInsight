#include <iostream>
#include <string>
#include <algorithm>
using i64 = long long;

int main() {
    std::string s;
    std::cin >> s;
    std::cout << (std::find(s.begin(), s.end(), '7') != s.end() ? "Yes\n" : "No\n");

    return 0;
}
