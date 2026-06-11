#include <iostream>
#include <string>
int main() {
    std::string x;
    for (std::cin >> x; x != "0"; std::cin >> x) {
        int s = 0;
        for (auto&& c: x) {
            s += c - '0';
        }
        std::cout << s << std::endl;
    }
}

