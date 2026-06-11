#include <iostream>
#include <algorithm>

int main(int argc, const char *argv[]) {
    std::string str;
    std::cin >> str;
    int q;
    std::cin >> q;
    std::string command, p;
    int a, b;
    for (int i = 0; i < q; i++) {
        std::cin >> command >> a >> b;
        if (command == "replace") {
            std::cin >> p;
            str.replace(a, b - a + 1, p);
        } else if (command == "reverse") {
            std::reverse(str.begin() + a, str.begin() + b + 1);
        } else if (command == "print") {
            std::cout << str.substr(a, b - a + 1) << std::endl;
        }
    }
    return 0;
}