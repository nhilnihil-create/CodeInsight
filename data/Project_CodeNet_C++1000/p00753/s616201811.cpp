#include <iostream>
#include <cmath>
#include <vector>

bool prime(int number) {
    int sq = sqrt(number);
    if (number % 2 == 0) {
        return false;
    }
    for (int i = 3; i <= sq; i += 2) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

int main(void) {
    int n;
    std::vector<int> count(246913, 0);
    count[2] = 1;
    for (int i = 3; i <= 246912; i++) {
        count[i] = count[i - 1];
        if (prime(i) == true) {
            count[i]++;    
        }
    }

    while (std::cin >> n) {
        if (n == 0) {
            break;
        }
        std::cout << count[2 * n] - count[n] << std::endl;
    }
    return 0;
}