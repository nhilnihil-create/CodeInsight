#include <iostream>

int main() {
    std::string s, t;
    std::cin >> s >> t;
    int m = 0;
    for (int i = 0; i < 3; i++) {
        if (s[i] == t[i]) {
            m++;
        }
    }
    std::cout << m << std::endl;

    return 0;
}