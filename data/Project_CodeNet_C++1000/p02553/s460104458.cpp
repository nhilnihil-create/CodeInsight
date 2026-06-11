// Copyright 2020 Tsutomu ISHIKAWA
// Author: Tsutomu ISHIKAWA

#include <iostream>
#include <algorithm>

int main() {
    int64_t a, b, c, d;
    std::cin >> a >> b >> c >> d;
    std::cout << std::max(std::max(a*c, a*d), std::max(b*c, b*d)) << std::endl;

    return 0;
}
