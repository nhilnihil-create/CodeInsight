#include <iostream>
#include <vector>
#include <algorithm>
using lint = long long;

lint func(lint& n) {
    lint total{}; lint fives{ 5 };
    while (fives > n) {
        total += n / fives;
        fives *= 5;
    }
    return total;
}

lint func2(lint& n, lint& fives) {
    lint total{}; lint seconds{ 2 };
    while (seconds > fives || seconds > n) {
        total += n / seconds;
        seconds *= 2;
    }
    return total;
}

int main() {
    lint N; std::cin >> N;
    if (N % 2 == 1) { std::cout << 0 << std::endl; return 0; }
    lint ans{};
    N /= 2;
    while (N > 0) {
        ans += N / 5;
        N /= 5;
    }
    std::cout << ans << std::endl;
}