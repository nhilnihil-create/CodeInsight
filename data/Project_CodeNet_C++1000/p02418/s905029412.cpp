//
// Created by tac on 2016/10/15.
//

#include <cstdlib>
#include <string>
#include <iostream>

int main() {
    std::string text;
    std::string search;

    std::cin >> text >> search;
    text += text;
    if (text.find(search) == std::string::npos) {
        std::cout << "No" << std::endl;
    } else {
        std::cout << "Yes" << std::endl;
    }

    return EXIT_SUCCESS;
}