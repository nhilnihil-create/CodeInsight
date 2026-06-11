#include <iostream>

int main () {

    int n;
    std::cin >> n;

    int count = 0;
    for(int a = 1; a < n; a++) {
        count += (n - 1) / a;
    }

    std::cout << count << std::endl;

    return 0;
}