#include <iostream>

int main() {
    char a = 'a', A = 'A', z = 'z', Z = 'Z';
    char tmp;

    std::cin >> tmp;

    if(tmp >= a && tmp <= z) {
        std::cout << a << std::endl;
    }
    else {
        std::cout << A << std::endl;
    }
    return 0;
}
