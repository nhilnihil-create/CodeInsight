#include <iostream>

int main(int argc, const char * argv[]) {
    std::string x;
    int sum;
    for ( ; getline(std::cin, x) && !(x == "0"); ) {
        sum = 0;
        for (size_t i = 0; i < x.length(); i++) {
            sum += x[i] - '0';
        }
        std::cout << sum << std::endl;
    }
    return 0;
}