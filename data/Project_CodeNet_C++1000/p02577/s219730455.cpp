#include <iostream>
#include <string>

int main() {
    std::string N;
    int sum = 0;

    std::cin >> N;

    for(auto tmp : N) {
        sum += tmp - '0';
    }

    if(sum % 9 == 0) {
        std::cout << "Yes" << std::endl;
    }
    else {
        std::cout << "No" << std::endl;
    }

    return 0;
}
