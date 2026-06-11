#include <iostream>
#include <vector>

int main() {
    std::vector<std::string> allhi = {
        "hi", "hihi", "hihihi", "hihihihi", "hihihihihi"
    };
    std::string s; std::cin >> s;
    for (const auto& ss: allhi) {
        if (ss == s) {
            std::cout << "Yes" << std::endl;
            return 0;
        }
    }
    std::cout << "No" << std::endl;
    return 0;
}