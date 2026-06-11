#include <iostream>

int main() {
    int a, b;
    std::cin >> a >> b;

    int n = 0;
    int sum = 1;
    while (sum < b) {
        sum += a - 1;
        n++;
    }
    
    std::cout << n << std::endl;
    return 0;
}