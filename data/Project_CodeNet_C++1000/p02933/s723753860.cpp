#include <iostream>
#include <string>

int main() {
    int a;
    std::string s;
    std::cin >> a >> s;
    std::cout << (a >= 3200 ? s : "red") << "\n";
}