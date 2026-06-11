#include <iostream>
#include <algorithm>
int main() {
    std::string s;
    for (std::cin >> s; s != "-"; std::cin >> s) {
        int m;
        std::cin >> m;
        while (m-- > 0) {
            int h;
            std::cin >> h;
            std::reverse(s.begin(), s.begin() + h);
            std::reverse(s.begin() + h, s.end());
            std::reverse(s.begin(), s.end());
        }
        std::cout << s << std::endl;
    }
}

