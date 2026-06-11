#include <iostream>

int main() {
    int n; std::string s; std::cin >> n >> s;
    std::cout << ((n < 3200)?"red":s) << std::endl;
    return 0;
}