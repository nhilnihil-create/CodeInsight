// Copyright 2020 Tsutomu ISHIKAWA
// Author: Tsutomu ISHIKAWA

#include <iostream>

int main() {
    int a;

    std::cin >> a;
    int mod_a = a % 2;
    if (mod_a == 0) {
        std::cout << a+1 << std::endl;
    } else {
        std::cout << a-1 << std::endl;
    }

    return 0;
}