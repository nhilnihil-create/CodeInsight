#include <iostream>
#include <algorithm>
#include <utility>
#include <map>

int calcAnswer(std::multimap< int, int > &input, int money) {
    int sum = 0;
    for (std::multimap< int, int >::reverse_iterator itr = input.rbegin(); itr != input.rend(); itr++) {
        if (itr->second > money) {
            sum += itr->first * (itr->second - money);
            money = 0;
        } else {
            money -= itr->second;
        }
    }
    return sum;
}

int main(void) {
    while (1) {
        int n, m;
        std::cin >> n >> m;

        if (n == 0 && m == 0) {
            break;
        }

        std::multimap< int, int > input;

        for (int i = 0; i < n; i++) {
            int length, danger;
            std::cin >> length >> danger;
            input.insert(std::make_pair(danger, length));
        }

        std::cout << calcAnswer(input, m) << std::endl;
    }

    return 0;
}