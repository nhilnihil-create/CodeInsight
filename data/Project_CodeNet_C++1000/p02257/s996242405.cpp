#include <iostream>

bool IsPrimeNumber(int num)
{
    // (2 <= num <= 10の8乗) なので、1の判定は略
    if ((num & 1) == 0) {
        return (num == 2);
    } else {
        int d = 3;
        while (d * d <= num) {
            if ((num % d) == 0) {
                return false;
            }
            d += 2;
        }
    }
    return true;
}

int main()
{
    int n;
    std::cin >> n;
    int count = 0;
    for (int i = 0; i < n; ++i) {
        int val;
        std::cin >> val;
        if (IsPrimeNumber(val)) {
            ++count;
        }
    }
    std::cout << count << std::endl;
    return 0;
}