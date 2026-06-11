#include <iostream>

int main() {
    long long int X, tmp = 100;
    int i = 0;

    std::cin >> X;

    do {
        i++;
        tmp = tmp + tmp / 100;
    }while(tmp < X);

    std::cout << i << std::endl;

    return 0;
}
